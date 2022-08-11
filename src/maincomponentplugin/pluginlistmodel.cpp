#include "pluginlistmodel.h"

#include <qabstractitemmodel.h>
#include <qglobal.h>
#include <qnamespace.h>

#include <QDebug>
#include <QDir>
#include <QMetaType>
#include <QVariant>

PluginListModel::PluginListModel(QObject *parent) : QAbstractListModel(parent)
{
#ifdef QT_DEBUG
    QDir dir("/home/lxz/plugins/");
    for (auto d : dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs)) {
        items << QString("file://%1/%2/main.qml").arg(dir.path()).arg(d);
    }
#endif
}
PluginListModel::~PluginListModel() {}

int PluginListModel::rowCount(const QModelIndex &parent) const
{
    return items.length();
}

QVariant PluginListModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
        case PathRole: {
            return items[index.row()];
        }
    }

    Q_UNIMPLEMENTED();

    return {};
}

QHash<int, QByteArray> PluginListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[PathRole] = "qml";
    return roles;
}
