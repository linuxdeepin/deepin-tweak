// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

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
