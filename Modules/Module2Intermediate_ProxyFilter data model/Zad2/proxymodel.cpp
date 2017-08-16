#include "proxymodel.h"

ProxyModel::ProxyModel(QObject *parent): QSortFilterProxyModel(parent),
    m_tresholdSize(0.0), m_tresholdName(""), graterThanTresh(true), sizeFiltering(true)
{
}

void ProxyModel::setTresholdSize(double size)
{
    if(m_tresholdSize != size)
        m_tresholdSize = size;
    invalidateFilter();
}

void ProxyModel::setTresholdDirection(int newDirection)
{
    if(graterThanTresh != (bool)newDirection)
        graterThanTresh = (bool)newDirection;
    invalidateFilter();
}

void ProxyModel::setTresholdName(QString text)
{
    if(m_tresholdName != text)
        m_tresholdName = text;
    invalidateFilter();
}

void ProxyModel::setSizeNameFlag(bool sizeNameFlag)
{
    if(sizeFiltering != sizeNameFlag)
        sizeFiltering = sizeNameFlag;
    invalidateFilter();
}

bool ProxyModel::filterAcceptsRow(int source_row,
                                  const QModelIndex &source_parent) const
{
    if(sizeFiltering)
    {
        QModelIndex indS = sourceModel()->index(source_row,
                                                   1, source_parent);
        if(sourceModel()->data(indS).toDouble() < m_tresholdSize)
            return graterThanTresh == true? false:true;
        return graterThanTresh == true? true:false;
    }
    else
    {
        QModelIndex indN = sourceModel()->index(source_row,
                                                   0, source_parent);
        if((sourceModel()->data(indN).toString()).contains(m_tresholdName, Qt::CaseInsensitive))
            return true;
        return false;
//        QString temp = QString("hello world, hello every one");
//        QString match = QString("hello world");
//        qWarning() << temp.contains(match);
    }
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation,
                                int role) const {
    return sourceModel()->headerData(section, orientation,
                                     role);
}
