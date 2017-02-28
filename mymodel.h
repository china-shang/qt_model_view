/*************************************************************************
    > File Name: mymodel.h
    > Created Time: 2017年02月18日 星期六 13时28分26秒
 ************************************************************************/
#ifndef _MYMODEL_H
#define _MYMODEL_H
#include <QAbstractTableModel>

class mymodel:public QAbstractTableModel{
    Q_OBJECT
public:
    mymodel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex())const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex())const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole)const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role)const Q_DECL_OVERRIDE;

    bool setData(const QModelIndex & index, const QVariant & value,
            int role = Qt::EditRole) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index)const Q_DECL_OVERRIDE;

private:
    int Row;
    int Col;
    QString m_gridData[3][3];
signals:
    void editComplete(const QString &);

};
#endif
