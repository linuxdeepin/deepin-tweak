#pragma once
#include <QDebug>
#include <QObject>
#include <QtQml>

class TestFunctions : public QObject {
    Q_OBJECT
public:
    explicit TestFunctions(QObject* parent = nullptr);
    ~TestFunctions();

    Q_INVOKABLE QString ping()
    {
        return "pong";
    }
};

class Launcher : public QObject {
    Q_OBJECT
public:
    explicit Launcher(QObject* parent = nullptr);
    ~Launcher() override;

    Q_INVOKABLE QString launch(const QString&     program,
                               const QStringList& args = {});
};
