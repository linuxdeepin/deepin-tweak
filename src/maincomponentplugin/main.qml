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

import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.7
import org.deepin.dtk 1.0

AppLoader {
    Component {
        ListView {
            anchors.fill: parent
            id: listView
            model: pluginListModel
            delegate: ColumnLayout {
                required property string path
                width: listView.width
                Label {
                    id: label
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.leftMargin: 10
                    Layout.rightMargin: 10
                    font.pixelSize: 22
                }
                Loader {
                    id: loader
                    Layout.leftMargin: 10
                    Layout.rightMargin: 10
                    source: path + "/main.qml"
                    asynchronous: true
                    visible: status == Loader.Ready
                    onLoaded: {
                      label.text = loader.item.displayName
                    }
                }
            }
        }
    }
}
