// SPDX - FileCopyrightText : 2022 UnionTech Software Technology Co., Ltd.

// SPDX - License - Identifier : GPL - 3.0 - or -later

#pragma once

#include "file.h"
#include "launcher.h"

#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>

class Staff : public QObject
{
    Q_OBJECT
public:
    Staff(QQmlEngine *engine, QJSEngine *scriptEngine)
        : QObject()
        , m_engine(engine)
        , m_jsEngine(scriptEngine)
    {}

    ~Staff() override {}

    Q_INVOKABLE inline LauncherCall *Launcher()
    {
        auto *call = new LauncherCall;
        QQmlEngine::setObjectOwnership(call, QQmlEngine::JavaScriptOwnership);
        return call;
    }

    Q_INVOKABLE FileBackend *File(const QString &file)
    {
        auto *call = new FileBackend(file);
        QQmlEngine::setObjectOwnership(call, QQmlEngine::JavaScriptOwnership);
        return call;
    }

private:
    QQmlEngine *m_engine;
    QJSEngine *m_jsEngine;
};

static void registerStaff()
{
    qmlRegisterUncreatableType<FileBackend>("org.deepin.tweak",
                                            1,
                                            0,
                                            "FileBackend",
                                            "cannot create filebackend object.");
    qmlRegisterType<FileMode>("org.deepin.tweak", 1, 0, "FileMode");
    qmlRegisterUncreatableType<LauncherCall>("org.deepin.tweak",
                                             1,
                                             0,
                                             "LauncherCall",
                                             "cannot create LauncherCall object.");
    qmlRegisterSingletonType<Staff>("org.deepin.tweak",
                                    1,
                                    0,
                                    "Tweak",
                                    [=](QQmlEngine *engine, QJSEngine *scriptEngine) {
                                        return new Staff(engine, scriptEngine);
                                    });
}
