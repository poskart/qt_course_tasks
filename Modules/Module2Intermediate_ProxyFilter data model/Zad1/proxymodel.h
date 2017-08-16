#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ProxyModel(QObject* parent = 0);
    bool filterAcceptsRow(int source_row,
                                       const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public slots:
    void setMinGravity(double minGravity);
    void setMinDensity(double minDensity);

private:
    double m_minGravity;
    double m_minDensity;
};

#endif // PROXYMODEL_H
