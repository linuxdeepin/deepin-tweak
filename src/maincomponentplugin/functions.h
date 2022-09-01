#pragma once
#include <optional>
#include <QDebug>
#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QStringList>
#include <QtQml>

class TestFunctions : public QObject
{
    Q_OBJECT
public:
    explicit TestFunctions(QObject *parent = nullptr);
    ~TestFunctions();

    Q_INVOKABLE QString ping() { return "pong"; }
};

class LauncherCall : public QObject
{
    Q_OBJECT
public:
    explicit LauncherCall() {}
    ~LauncherCall() override {}

    Q_INVOKABLE inline LauncherCall *program(const QString &program)
    {
        m_program = program;
        return this;
    }
    Q_INVOKABLE inline LauncherCall *arguments(const QStringList &arguments)
    {
        m_arguments = arguments;
        return this;
    }
    Q_INVOKABLE inline LauncherCall *timeout(const int timeout)
    {
        m_timeout = timeout;
        return this;
    }
    Q_INVOKABLE QVariantMap call();
    Q_INVOKABLE void asyncCall(const QJSValue &jsCallback);

private:
    QString m_program;
    QStringList m_arguments;
    std::optional<int> m_timeout;
};

class Launcher : public QObject
{
    Q_OBJECT
public:
    explicit Launcher(QQmlEngine *engine, QJSEngine *scriptEngine)
        : QObject(engine)
        , m_engine(engine)
        , m_jsEngine(scriptEngine)
    {}
    ~Launcher() override {}

    Q_INVOKABLE inline LauncherCall *create()
    {
        LauncherCall *call = new LauncherCall;
        QQmlEngine::setObjectOwnership(call, QQmlEngine::JavaScriptOwnership);
        return call;
    }

private:
    QQmlEngine *m_engine;
    QJSEngine *m_jsEngine;
};

// Q_DECLARE_METATYPE(LauncherCall *);
