#include "functions.h"

#include <QProcess>
#include <QScopedPointer>

TestFunctions::TestFunctions(QObject* parent) : QObject(parent) {}
TestFunctions::~TestFunctions() {}

Launcher::Launcher(QObject* parent) : QObject(parent) {}
Launcher::~Launcher() {}

QString Launcher::launch(const QString& program, const QStringList& args)
{
    QScopedPointer<QProcess> process(new QProcess(this));
    process->setProgram(program);
    process->setArguments(args);
    process->start();
    process->waitForFinished(-1);
    QByteArray bytes = process->readAllStandardOutput();
    return QString::fromLocal8Bit(bytes);
}
