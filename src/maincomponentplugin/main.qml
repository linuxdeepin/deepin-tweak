// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: GPL-3.0-or-later

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
                    font: DTK.fontManager.t3
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
