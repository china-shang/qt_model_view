/*************************************************************************
    > File Name: mymodel.h
    > Created Time: 2017年02月18日 星期六 13时28分26秒
 ************************************************************************/
#ifndef MYMODEL_H
#include <QAbstractTableModel>

class mymodel:public QAbstractTableModel{
    Q_OBJECT
public:
    mymodel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex())const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex())const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole)const Q_DECL_OVERRIDE;

};
#endif
