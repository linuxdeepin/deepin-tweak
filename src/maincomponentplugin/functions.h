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
