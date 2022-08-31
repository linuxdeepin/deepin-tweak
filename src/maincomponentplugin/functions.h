#pragma once
#include <optional>
#include <QDebug>
#include <QObject>
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
    explicit LauncherCall();
    ~LauncherCall() override;

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

// Q_DECLARE_METATYPE(LauncherCall *);
