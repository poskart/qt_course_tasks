#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QVariant>
#include <QSortFilterProxyModel>

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ProxyModel(QObject* parent = 0);
    bool filterAcceptsRow(int source_row,
                                       const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void setTresholdSize(double size);
    void setTresholdName(QString text);
    void setSizeNameFlag(bool sizeNameFlag);
public slots:
    void setTresholdDirection(int newDirection);
private:
    double m_tresholdSize;
    QString m_tresholdName;
    bool graterThanTresh;
    bool sizeFiltering; //size filtering when true, name filtering when false
};

#endif // PROXYMODEL_H
