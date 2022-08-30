/*
 * Copyright (C) 2022 UnionTech Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "maincomponentplugin.h"

#include <qvariant.h>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>

#include "functions.h"
#include "pluginlistmodel.h"

DQUICK_USE_NAMESPACE

MainComponentPlugin::MainComponentPlugin(QObject *parent)
    : QObject(parent)
{
    pluginListModel = new PluginListModel(this);
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
    engine->rootContext()->setContextProperty("testFunction", new TestFunctions);
    engine->rootContext()->setContextProperty("launcher", new Launcher(engine));
}
