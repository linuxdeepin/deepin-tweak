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

#ifndef MAINCOMPONENTPLUGIN_H
#define MAINCOMPONENTPLUGIN_H

#include <dqmlappmainwindowinterface.h>

class QQmlComponent;
class PluginListModel;
class MainComponentPlugin : public QObject, public DTK_QUICK_NAMESPACE::DQmlAppMainWindowInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID DQmlAppMainWindowInterface_iid)
    Q_INTERFACES(DTK_QUICK_NAMESPACE::DQmlAppMainWindowInterface)
public:
    MainComponentPlugin(QObject *parent = nullptr);
    ~MainComponentPlugin() override;

    QUrl mainComponentPath() const override;
    void initialize(QQmlApplicationEngine *engine) override;

private:
    PluginListModel *pluginListModel;
};

#endif // MAINCOMPONENTPLUGIN_H
