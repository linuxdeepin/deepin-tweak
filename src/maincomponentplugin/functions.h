#pragma once
#include <QDebug>
#include <QObject>
#include <QtQml>

class TestFunctions : public QObject
{
    Q_OBJECT
public:
    explicit TestFunctions(QObject *parent = nullptr);
    ~TestFunctions();

    Q_INVOKABLE QString ping() { return "pong"; }
};

class Launcher : public QObject
{
    Q_OBJECT
public:
    explicit Launcher(QObject *parent);
    ~Launcher() override;

    Q_INVOKABLE QString launch(const QString &program, const QStringList &args = {});
    Q_INVOKABLE void asyncLaunch(const QString &program, const QJSValue &jsCallback);
    Q_INVOKABLE void asyncLaunchWithArgs(const QString &program,
                                         const QStringList &args,
                                         const QJSValue &jsCallback);

protected:
    void onLaunchFinished(const QString &result, const QJSValue &callback);
};
