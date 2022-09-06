# SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

# SPDX-License-Identifier: GPL-3.0-or-later

#include "pluginlistmodel.h"

#include <QDebug>
#include <QDir>
#include <QMetaType>
#include <QStandardPaths>
#include <QVariant>
#include <QtGlobal>

PluginListModel::PluginListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    const QStringList &locations = QStandardPaths::standardLocations(
        QStandardPaths::AppDataLocation);
    for (const auto &location : locations) {
        QDir dir(QString("%1/plugins").arg(location));
        for (auto d : dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs)) {
            qDebug() << dir.path();
            items << QString("file://%1/%2").arg(dir.path()).arg(d);
        }
    }
}

PluginListModel::~PluginListModel() {}

int PluginListModel::rowCount(const QModelIndex &parent) const
{
    return items.length();
}

QVariant PluginListModel::data(const QModelIndex &index, int role) const
{
    return role == PathRole ? items[index.row()] : QAbstractItemModel::data(index, role);
}

QHash<int, QByteArray> PluginListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[PathRole] = "path";
    return roles;
}
