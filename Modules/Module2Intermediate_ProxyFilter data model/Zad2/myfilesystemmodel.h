#ifndef MYFILESYSTEMMODEL_H
#define MYFILESYSTEMMODEL_H

#include <QAbstractTableModel>
#include <QFileSystemModel>
#include <QAbstractTableModel>
#include <QVariant>
#include <QDebug>
#include "file.h"

class MyFileSystemModel : public QAbstractTableModel
{
public:
    MyFileSystemModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data (const QModelIndex & index,
                   int role = Qt::DisplayRole) const;
    QVariant headerData(int section,Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    QList<File> m_fileList;
};

#endif // MYFILESYSTEMMODEL_H
