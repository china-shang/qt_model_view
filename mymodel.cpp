/*************************************************************************
    > File Name: /home/zh/QT/model_view1/mymodel.c
    > Created Time: 2017年02月18日 星期六 13时37分19秒
 ************************************************************************/
#include <QDebug>
#include <QFont>
#include <QBrush>
#include "mymodel.h"

mymodel::mymodel(QObject *parent):QAbstractTableModel(parent)
{
}
int mymodel::rowCount(const QModelIndex &)const
{
    return 3;
}
int mymodel::columnCount(const QModelIndex &)const
{
    return 3;
}
QVariant mymodel::data(const QModelIndex &index, int role)const 
{
    int row = index.row();
    int col = index.column();
    //qDebug()<<QString("row%1, Col%2")
                //.arg(row).arg(col);
    switch(role){
    case Qt::DisplayRole:
        if(row == 0 && col == 1)
            return QString("left");
        if(row == 1 && col == 1)
            return QString("right");
        return QString("row%1, Col%2")
                .arg(row+1).arg(col+1);
        break;
    case Qt::FontRole:
        if(row == 0 && col == 0)
            {
                QFont boldFont;
                boldFont.setBold(true);
                return boldFont;
            }
        break;
    case Qt::BackgroundRole:
        if(row == 1 && col == 2)
        {
            QBrush brush;
            brush.setColor(Qt::yellow);
            return brush;
        }
    case Qt::TextAlignmentRole:
        if(row == 1 && col == 1)
        {
            return Qt::AlignRight+Qt::AlignVCenter;
        }
    case Qt::CheckStateRole:
        if(row == 1 && col == 0)
        {
            return Qt::Checked;
        }
    }
    return QVariant();
}
