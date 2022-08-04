#ifndef PLUGINLISTMODEL_H_
#define PLUGINLISTMODEL_H_

#include <QAbstractListModel>
#include <QList>
#include <qvariant.h>

struct PluginItem {
  QString name;
  QString qml;
  QString author;
};

class PluginListModel : public QAbstractListModel {
  Q_OBJECT
public:
  explicit PluginListModel(QObject *parent = nullptr);
  ~PluginListModel() override;

  enum AnimalRoles { NameRole = Qt::UserRole + 1, PathRole, AuthorRole };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

private:
  QList<PluginItem> items;
};

#endif // PLUGINLISTMODEL_H_
