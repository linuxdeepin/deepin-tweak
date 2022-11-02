// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Layouts 1.15
import org.deepin.dtk 1.0

RowLayout {
    anchors.fill: parent
    spacing: 10
    ListView {
        id: listView
        clip: true
        Layout.alignment: Qt.AlignVCenter
        // TODO: not align to VCenter
        // NOTE: limit show five item
        Layout.minimumHeight: 5 * 36
        Layout.maximumHeight: parent.height
        Layout.preferredWidth: 180
        Layout.leftMargin: 10
        model: pluginListModel
        focus: true
        interactive: true
        highlight: Rectangle {
            color: 'gray'
            radius: 10
            Rectangle {
                color: 'red'
                width: 5
                height: 20
                radius: 5
                x: 5
                y: 8
            }
        }
        delegate: Rectangle {
            required property int index
            // NOTE: Custom properties need to be kept at the end,
            //       otherwise the index property will not be accessible
            required property string path
            id: item
            radius: 10
            height: 36
            width: listView.width
            color: 'transparent'
            Item {
                id: row
                anchors.fill: parent
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        listView.currentIndex = index
                    }
                    onEntered: {
                        item.color = Qt.rgba(1, 1, 1, 0.4)
                    }
                    onExited: {
                        item.color = "transparent"
                    }
                }
                RowLayout {
                    Layout.alignment: Qt.AlignVCenter
                    anchors.fill: parent
                    Rectangle {
                        width: 10
                        visible: item.ListView.isCurrentItem
                    }
                    Image {
                        id: icon
                        fillMode: Image.PreserveAspectFit
                        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                        Layout.preferredWidth: 22
                        Layout.preferredHeight: 22
                        Layout.leftMargin: 5
                    }
                    Text {
                        id: displayName
                        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                        Layout.fillWidth: true
                        font.pixelSize: 12
                    }
                    Loader {
                        id: _loader
                        visible: false
                        source: path + "/main.qml"
                        onLoaded: {
                            icon.source = path + "/assets/" + _loader.item.icon
                            displayName.text = _loader.item.displayName
                        }
                    }
                }
            }
        }
        onCurrentItemChanged: {
            view.setSource(listView.currentItem.path + "/main.qml")
        }
        Component.onCompleted: {
        }
    }
    Rectangle {
        id: view
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.bottomMargin: 10
        Layout.rightMargin: 10
        color: 'white'
        radius: 15

        function setSource(source) {
            loader.source = source
        }

        Loader {
            id: loader
            anchors.fill: parent
            asynchronous: true
            visible: status == Loader.Ready
        }
    }
}

