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

#ifndef PRELOADPLUGIN_H
#define PRELOADPLUGIN_H

#include <dqmlapppreloadinterface.h>

class QQmlComponent;
class PreloadPlugin : public QObject, public DTK_QUICK_NAMESPACE::DQmlAppPreloadInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID DQmlAppPreloadInterface_iid)
    Q_INTERFACES(DTK_QUICK_NAMESPACE::DQmlAppPreloadInterface)
public:
    PreloadPlugin(QObject *parent = nullptr);
    ~PreloadPlugin() override;

    virtual QUrl preloadComponentPath() const override;
};

#endif // PRELOADPLUGIN_H
