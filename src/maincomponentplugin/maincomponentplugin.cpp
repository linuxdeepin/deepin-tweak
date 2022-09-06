# SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

# SPDX-License-Identifier: GPL-3.0-or-later

#include "maincomponentplugin.h"

#include <qvariant.h>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>

#include "pluginlistmodel.h"
#include "staff/file.h"
#include "staff/launcher.h"

DQUICK_USE_NAMESPACE

MainComponentPlugin::MainComponentPlugin(QObject *parent)
    : QObject(parent)
{
    pluginListModel = new PluginListModel(this);
    qmlRegisterType<LauncherCall>("org.deepin.tweak", 1, 0, "LauncherCall");
    qmlRegisterSingletonType<Launcher>("org.deepin.tweak",
                                       1,
                                       0,
                                       "Launcher",
                                       [=](QQmlEngine *engine, QJSEngine *scriptEngine) {
                                           return new Launcher(engine, scriptEngine);
                                       });

    File::registerType();
}

MainComponentPlugin::~MainComponentPlugin() {}

QUrl MainComponentPlugin::mainComponentPath() const
{
    // 返回程序的主控件部分 qml 文件，请确保该文件存在
    return QUrl("qrc:///main.qml");
}

void MainComponentPlugin::initialize(QQmlApplicationEngine *engine)
{
    engine->rootContext()->setContextProperty("pluginListModel", pluginListModel);
}
