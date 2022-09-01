#include "functions.h"

#include <QJSValue>
#include <QMetaType>
#include <QProcess>
#include <QQmlContext>
#include <QQmlEngine>
#include <QScopedPointer>
#include <QTimer>

TestFunctions::TestFunctions(QObject *parent)
    : QObject(parent)
{}

TestFunctions::~TestFunctions() {}

QVariantMap LauncherCall::call()
{
    QScopedPointer<QProcess> process(new QProcess);
    process->setProgram(m_program);
    process->setArguments(m_arguments);
    process->start();
    process->waitForFinished(m_timeout.value_or(-1));

    QVariantMap map;
    map["allStandardOutput"] = process->readAllStandardOutput();
    map["allStandardError"] = process->readAllStandardError();

    return map;
}

void LauncherCall::asyncCall(const QJSValue &jsCallback)
{
    QProcess *process = new QProcess;

    auto result = [=] {
        QJSValue callback = jsCallback;
        if (callback.isCallable()) {
            QVariantMap map;
            map["allStandardOutput"] = process->readAllStandardOutput();
            map["allStandardError"] = process->readAllStandardError();
            QJSValue value = jsCallback.engine()->toScriptValue<QVariantMap>(map);
            callback.call({value});
        }
    };

    QObject::connect(process,
                     static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
                     process,
                     result);

    process->setProgram(m_program);
    process->setArguments(m_arguments);
    process->start();

    if (m_timeout.has_value()) {
        QTimer::singleShot(m_timeout.value(), process, [=] {
            process->kill();
            process->deleteLater();
            result();
        });
    }
}
