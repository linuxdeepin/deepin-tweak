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
    qRegisterMetaType<PluginItem>("PluginItem");

#ifdef QT_DEBUG
    QDir dir("/home/lxz/plugins/");
    for (auto d : dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs)) {
        items << PluginItem{
            .name   = d,
            .qml    = QString("file://%1/%2/main.qml").arg(dir.path()).arg(d),
            .author = "I'm author.",
        };
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
        case NameRole: {
            return items[index.row()].name;
        }
        case PathRole: {
            return items[index.row()].qml;
        }
        case AuthorRole: {
            return items[index.row()].author;
        }
    }

    Q_UNIMPLEMENTED();
}

QHash<int, QByteArray> PluginListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole]   = "name";
    roles[AuthorRole] = "author";
    roles[PathRole]   = "qml";
    return roles;
}
