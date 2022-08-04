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
                required property string name
                required property string qml
                required property string author
                width: listView.width
                Label {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.leftMargin: 10
                    Layout.rightMargin: 10
                    text: name + " - " + author
                    font.pixelSize: 22
                }
                Loader {
                    Layout.leftMargin: 10
                    Layout.rightMargin: 10
                    source: qml
                    Rectangle {
                        anchors.fill: parent
                        color: "#66ccff"
                        opacity: 0.05
                    }
                }
            }
        }
    }
}
