// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.0
ListModel {
    ListElement {
        title: qsTr("Index")
        img: "/images/Index.png"
        source: "Categories/Index.qml"
    }
    ListElement {
        title: qsTr("Desktop Environment")
        img: "/images/DE.png"
        source: "Categories/DE.qml"
    }
    ListElement {
        title: qsTr("Application")
        img: "/images/Application.png"
        source: "Categories/Application.qml"
    }
    ListElement {
        title: qsTr("Kernel")
        img: "/images/Kernel.png"
        source: "Categories/Kernel.qml"
    }
    ListElement {
        title: qsTr("Environment")
        img: "/images/Environment.png"
        source: "Categories/Environment.qml"
    }
    ListElement {
        title: qsTr("Boot Menu")
        img: "/images/BootMenu.png"
        source: "Categories/BootMenu.qml"
    }
    ListElement {
        title: qsTr("Other")
        img: "/images/Other.svg"
        source: "Categories/Other.qml"
    }
}
