// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Layouts 1.15
import "./Utils"

RowLayout {
    anchors.fill: parent
    spacing: 10
    Category {
        id: category
        Layout.fillHeight: true
        Layout.preferredWidth: Utils.categoryWidth
        Layout.leftMargin: Utils.margin
        onCurrentItemChanged: {
            content.source = category.model.get(category.currentIndex).source
        }
    }
    Rectangle {
        clip: true
        Layout.fillHeight: true
        Layout.fillWidth: true
        radius: Utils.listRadius
        color: Utils.transparent
        Loader {
            id: content
            anchors.fill: parent
        }
    }
}

