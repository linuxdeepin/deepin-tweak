// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.7
import Qt.labs.platform 1.1
import org.deepin.dtk 1.0
import org.deepin.tweak 1.0

RowLayout {
    id: frame
    property string displayName: "Title height"
    property string description: "Change window title height"
    property string version: "1.0.0"
    property string author: "justforlxz"
    property string icon: "icon.png"

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
            text: qsTr("Apply")
            onClicked: () => {
                           const setTitleBar = (theme, value) => {
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
}
