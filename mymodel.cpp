/*************************************************************************
    > File Name: /home/zh/QT/model_view1/mymodel.c
    > Created Time: 2017年02月18日 星期六 13时37分19秒
 ************************************************************************/
#include "mymodel.h"

mymodel::mymodel(QObject *parent):QAbstractTableModel(parent)
{
}
int mymodel::rowCount(const QModelIndex &)const
{
    return 4;
}
int mymodel::columnCount(const QModelIndex &)const
{
    return 3;
}
QVariant mymodel::data(const QModelIndex &index, int role)const 
{
    if(role == Qt::DisplayRole)
        return QString("table");
    return QVariant();
}
