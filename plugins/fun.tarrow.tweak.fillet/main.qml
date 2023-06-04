// SPDX-FileCopyrightText: 2023 ice

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.7
import org.deepin.dtk 1.0
import org.deepin.tweak 1.0

ColumnLayout {
    id: root

    property string displayName: qsTr("Fillet size")
    property string description: qsTr("Adjust window fillet size")
    property string version: "0.0.1"
    property string author: "ice"
    property string icon: "icon.svg"
    property int filletSize: 18

    function getFilletSize() {
        let order = Tweak.newLauncher().program("gsettings").arguments(["get", "com.deepin.xsettings", "dtk-window-radius"]);
        order.asyncCall((callback) => {
            filletSize = callback.allStandardOutput;
        });
    }

    function setFilletSize(num) {
        let order = Tweak.newLauncher().program("gsettings").arguments(["set", "com.deepin.xsettings", "dtk-window-radius", num]);
        order.asyncCall((callback) => {
            filletSize = num;
        });
    }

    Component.onCompleted: getFilletSize()

    Label {
        Layout.topMargin: 10
        Layout.leftMargin: 10
        Layout.rightMargin: 10
        text: qsTr("Fillet size (0-18)")
        font.bold: true
        font.pixelSize: 15
    }

    RowLayout {
        spacing: 10
        Layout.fillWidth: true
        Layout.topMargin: 10
        Layout.leftMargin: 10
        Layout.rightMargin: 10

        SpinBox {
            id: control

            from: 0
            to: 18
            value: filletSize
            editable: true
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
        }

        Button {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.preferredWidth: 118
            text: qsTr("Reset to default")
            onClicked: {
                setFilletSize(18);
            }
        }

    }

    Item {
        Layout.fillHeight: true
    }

    Button {
        id: accept

        Layout.fillWidth: true
        Layout.leftMargin: 10
        Layout.rightMargin: 10
        Layout.bottomMargin: 10
        text: qsTr("Apply")
        onClicked: {
            setFilletSize(control.value);
        }
    }

}
