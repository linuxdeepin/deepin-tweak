// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.7
import org.deepin.dtk 1.0
import org.deepin.tweak 1.0

RowLayout {
    property string displayName: "Title height"
    property string description: "Change window title height"
    property string version: "1.0.0"
    property string author: "justforlxz"
    property string icon: "icon.png"
    id: frame

    function getEnv(_key) {
        for (const p of env) {
            const key = p.split('=')[0];
            const value = p.slice(key.length + 1, p.length);
            if (key === _key) {
                return value;
            }
        }
        return '';
    }

    Row {
        spacing: 10
        SpinBox {
            id: control
            from: 0
            to: 9999
            value: 50

            validator: IntValidator {
                locale: control.locale.name
                bottom: Math.min(control.from, control.to)
                top: Math.max(control.from, control.to)
            }
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            id: accept
            text: qsTr("Accept")
            onClicked: () => {
                           const setTitleBar = (theme, value) => {
                               const path = getEnv('HOME') + '/.local/share/deepin/themes/deepin/'+ theme + '/titlebar.ini';
                               const settings = Tweak.newSettings(path);
                               settings.beginGroup('Active');
                               settings.setValue('height', value);
                               settings.endGroup();
                               settings.beginGroup('Inactive');
                               settings.setValue('height', value);
                           }
                           setTitleBar('light', control.value);
                           setTitleBar('dark', control.value);

                           // restart wm
                           // TODO: use dbus but wait for v23
                           const wm = Tweak.newLauncher();
                           wm.program('/usr/bin/kwin_no_scale');
                           wm.arguments(['--replace']);
                           wm.startDetached();
                       }
        }
    }
    Component.onCompleted: () => {
                               const value = getEnv('HOME') + '/.local/share/deepin/themes/deepin/light/titlebar.ini';
                               const settings = Tweak.newSettings(value);
                               settings.beginGroup('Active');
                               const height = settings.value('height');
                               if (height !== undefined) {
                                   control.value = height
                               }
                           }
}
