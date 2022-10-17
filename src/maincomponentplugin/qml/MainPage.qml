// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Layouts 1.15

RowLayout {
    anchors.fill: parent
    Category {
        id: category
        Layout.fillHeight: true
        Layout.preferredWidth: 200
        onCurrentItemChanged: {
            console.log(category.currentIndex);
            // load content.model
            // TODO: not switch model
            content.model = pluginListModel
        }
    }
    Rectangle {
        id: view
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.leftMargin: 20
        Layout.topMargin: 10
        Layout.bottomMargin: 10
        color: 'white'
        radius: 15
        Content {
            id: content
            anchors.fill: parent
            Layout.leftMargin: 20
            Layout.rightMargin: 20
        }
    }
}
