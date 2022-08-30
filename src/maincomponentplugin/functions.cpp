#include "functions.h"

#include <QJSValue>
#include <QProcess>
#include <QScopedPointer>

TestFunctions::TestFunctions(QObject *parent)
    : QObject(parent)
{}

TestFunctions::~TestFunctions() {}

Launcher::Launcher(QObject *parent)
    : QObject(parent)
{}

Launcher::~Launcher() {}

QString Launcher::launch(const QString &program, const QStringList &args)
{
    QScopedPointer<QProcess> process(new QProcess(this));
    process->setProgram(program);
    process->setArguments(args);
    process->start();
    process->waitForFinished(-1);
    QByteArray bytes = process->readAllStandardOutput();
    return QString::fromLocal8Bit(bytes);
}

void Launcher::asyncLaunch(const QString &program, const QJSValue &jsCallback)
{
    return asyncLaunchWithArgs(program, {}, jsCallback);
}

void Launcher::asyncLaunchWithArgs(const QString &program,
                                   const QStringList &args,
                                   const QJSValue &jsCallback)
{
    QSharedPointer<QProcess> process(new QProcess(this));
    connect(process.data(),
            static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            this,
            [=] { return onLaunchFinished(process->readAll(), jsCallback); });

    process->setProgram(program);
    process->setArguments(args);
    process->start();
}

void Launcher::onLaunchFinished(const QString &result, const QJSValue &jsCallback)
{
    QJSValue callback = jsCallback;
    if (callback.isCallable()) {
        callback.call({QJSValue(result)});
    }
}
