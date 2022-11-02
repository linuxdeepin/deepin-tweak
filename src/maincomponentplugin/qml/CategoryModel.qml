// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.0

ListModel {
    ListElement {
        title: qsTr("Welcome")
        img: "/images/Welcome.png"
        source: "Categories/Welcome.qml"
        isVisible: true
    }
    ListElement {
        title: qsTr("Other")
        img: "/images/Other.svg"
        source: "Categories/Other.qml"
        isVisible: true
    }
}

