// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Layouts 1.15

RowLayout {
    anchors.fill: parent
    spacing: 10
    Category {
        id: category
        Layout.fillHeight: true
        Layout.preferredWidth: 200
        onCurrentItemChanged: {
            content.source = category.model.get(category.currentIndex).source
        }
    }
    Loader {
        id: content
        Layout.fillHeight: true
        Layout.fillWidth: true
    }
}
