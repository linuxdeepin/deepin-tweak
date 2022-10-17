// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Layouts 1.15
import org.deepin.dtk 1.0

ListView {
    clip: true
    id: listView
    delegate: ColumnLayout {
        required property string path
        spacing: listView.spacing || 10
        width: ListView.view.width
        Text {
            id: label
            Layout.fillWidth: true
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            font: DTK.fontManager.t3
        }
        Loader {
            id: loader
            Layout.fillWidth: true
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            source: path + "/main.qml"
            asynchronous: true
            visible: status == Loader.Ready
            onLoaded: {
                label.text = loader.item.displayName
            }
        }
        Rectangle {
            color: "#999999"
            Layout.preferredHeight: 1
            Layout.fillWidth: true
            Layout.topMargin: 10
            Layout.bottomMargin: 10
            visible: false
        }
    }
}
