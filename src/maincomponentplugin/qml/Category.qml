// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import "./Utils"

ListView {
    id: listView
    model: CategoryModel {}
    Layout.topMargin: Utils.margin
    spacing: Utils.spacing
    focus: true
    interactive: false
    highlight: Rectangle {
        color: palette.highlight
        radius: Utils.listRadius
        Rectangle {
            color: palette.highlightedText
            width: 5
            height: 20
            radius: 5
            x: 5
            y: 8
        }
    }
    delegate: Rectangle {
        id: item
        radius: Utils.listRadius
        height: row.height
        width: listView.width
        color: Utils.transparent
        Item {
            id: row
            width: listView.width
            height: 36
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listView.currentIndex = index
                    item.color = Utils.transparent
                }
                onEntered: {
                    if (listView.currentIndex === index) {
                        return;
                    }
                    item.color = palette.base
                }
                onExited: {
                    item.color = Utils.transparent
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignVCenter
                anchors.fill: parent
                Rectangle {
                    width: 10
                    visible: listView.currentIndex === index
                }

                Image {
                    source: img
                    fillMode: Image.PreserveAspectFit
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                    Layout.preferredWidth: 22
                    Layout.preferredHeight: 22
                    Layout.leftMargin: 5
                }

                Text {
                    text: title
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                    Layout.fillWidth: true
                    font.pixelSize: 12
                }
            }
        }
    }
}

