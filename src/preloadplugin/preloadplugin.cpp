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

#include "preloadplugin.h"

#include <QUrl>

DQUICK_USE_NAMESPACE

PreloadPlugin::PreloadPlugin(QObject *parent)
    : QObject(parent)
{

}

PreloadPlugin::~PreloadPlugin()
{

}

QUrl PreloadPlugin::preloadComponentPath() const
{
    // 预览组件的 qml 路径
    return QUrl("qrc:///Preload.qml");
}
