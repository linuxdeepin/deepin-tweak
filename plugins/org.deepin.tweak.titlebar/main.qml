// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.7
import Qt.labs.platform 1.1
import org.deepin.dtk 1.0
import org.deepin.tweak 1.0

ColumnLayout {
    id: frame
    spacing: 10
    property string displayName: qsTr("Title height")
    property string description: qsTr("Change window title height")
    property string version: "1.0.0"
    property string author: "justforlxz"
    property string icon: "icon.png"

    function loadConfig() {
        const paths = StandardPaths.standardLocations(StandardPaths.GenericDataLocation)
        if (paths.length === 0) {
            return;
        }
        const path = paths[0] + '/deepin/themes/deepin/light/titlebar.ini';
        const settings = Tweak.newSettings(path);
        settings.beginGroup('Active');
        const height = settings.value('height');
        if (height !== undefined) {
            control.value = height
        }
    }

    function setHeight(value) {
        const setTitleBar = function(theme, value) {
            const paths = StandardPaths.standardLocations(StandardPaths.GenericDataLocation)
            if (paths.length === 0) {
                return;
            }
            const path = paths[0] + '/deepin/themes/deepin/'+ theme + '/titlebar.ini';
            const settings = Tweak.newSettings(path);
            settings.beginGroup('Active');
            settings.setValue('height', value);
            settings.endGroup();
            settings.beginGroup('Inactive');
            settings.setValue('height', value);
        }
        setTitleBar('light', value);
        setTitleBar('dark', value);

        // restart wm
        // TODO: use dbus but wait for v23
        const wm = Tweak.newLauncher();
        wm.program('/usr/bin/kwin_no_scale');
        wm.arguments(['--replace']);
        wm.startDetached();
    }

    RowLayout {
        spacing: 10
        SpinBox {
            id: control
            from: 0
            to: 9999
            value: 40
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true

            validator: IntValidator {
                locale: control.locale.name
                bottom: Math.min(control.from, control.to)
                top: Math.max(control.from, control.to)
            }
        }
        Button {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            text: qsTr("Reset to default")
            onClicked: {
                setHeight(40)
                loadConfig()
            }
        }
    }

    Button {
        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: true
        id: accept
        text: qsTr("Apply")
        onClicked: setHeight(control.value)
    }

    Component.onCompleted: loadConfig()
}
