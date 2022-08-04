#include "pluginlistmodel.h"
#include <QMetaType>
#include <QVariant>
#include <qabstractitemmodel.h>
#include <qglobal.h>
#include <qnamespace.h>

PluginListModel::PluginListModel(QObject *parent) : QAbstractListModel(parent) {
  qRegisterMetaType<PluginItem>("PluginItem");
#ifdef QT_DEBUG
  items << PluginItem{
      .name = "测试标题 1", .qml = "file:///home/lxz/1.qml", .author = "lxz"};
  items << PluginItem{
      .name = "测试标题 2", .qml = "file:///home/lxz/1.qml", .author = "2"};
  items << PluginItem{
      .name = "测试标题 3", .qml = "file:///home/lxz/1.qml", .author = "3"};
  items << PluginItem{
      .name = "测试标题 4", .qml = "file:///home/lxz/1.qml", .author = "4"};
  items << PluginItem{
      .name = "测试标题 5", .qml = "file:///home/lxz/1.qml", .author = "5"};
#endif
}
PluginListModel::~PluginListModel() {}

int PluginListModel::rowCount(const QModelIndex &parent) const {
  return items.length();
}

QVariant PluginListModel::data(const QModelIndex &index, int role) const {
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

QHash<int, QByteArray> PluginListModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[NameRole] = "name";
  roles[AuthorRole] = "author";
  roles[PathRole] = "qml";
  return roles;
}
