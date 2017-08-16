#include "myfilesystemmodel.h"

MyFileSystemModel::MyFileSystemModel(QObject* parent) :
QAbstractTableModel(parent)
{
    QString path = QDir::currentPath();

    QDir mdir(path);
    if(!mdir.exists())
        qDebug () <<"Wrong directory!";
    mdir.setFilter(QDir::Files);
    foreach (QFileInfo fileInfo, mdir.entryInfoList())
    {
        m_fileList.append(File(fileInfo.fileName(), fileInfo.size(), fileInfo.baseName()));
    }
}

int MyFileSystemModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

int MyFileSystemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_fileList.size();
}

QVariant MyFileSystemModel::data (const QModelIndex & index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (index.row() >= m_fileList.size() || index.row() < 0) return QVariant();

    if (role == Qt::DisplayRole) {
        int tt = index.row();
        //struct File & f = m_fileList.at(index.row());
        const File& file = m_fileList.at(index.row());
        switch (index.column()) {
        case 0:
            return file.name;
        case 1:
            return file.size;
        case 2:
            return file.type;
        default:
            return QVariant();
        }
    }
    else if (role == Qt::TextAlignmentRole) {
        if (index.column() == 0)
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return Qt::AlignCenter;
    }
    return QVariant();
}

QVariant MyFileSystemModel::headerData(int section,
                                      Qt::Orientation orientation,int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("Size [B]");
        case 2:
            return tr("Type");
        default:
            return QVariant();
        }
    }

    return section + 1;
}
