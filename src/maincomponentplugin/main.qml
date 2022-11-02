// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.11
import org.deepin.dtk 1.0
import QtQuick.Layouts 1.15

AppLoader {
    Component {
        RowLayout {
            anchors.fill: parent
            Loader {
                Layout.fillHeight: true
                Layout.fillWidth: true
                source: 'qml/MainPage.qml'
            }
        }
    }
}
