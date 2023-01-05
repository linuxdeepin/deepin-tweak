// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

// SPDX-License-Identifier: LGPL-3.0-or-later

#include <DAppLoader>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

DQUICK_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DAppLoader appLoader("org.deepin.tweak");
#ifdef LOCALLIBPATH
    appLoader.addPluginPath(LOCALLIBPATH);
#endif
    return appLoader.exec(argc, argv);
}
