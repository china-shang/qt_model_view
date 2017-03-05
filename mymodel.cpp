/*************************************************************************
    > File Name: /home/zh/QT/model_view1/mymodel.c
    > Created Time: 2017年02月18日 星期六 13时37分19秒
 ************************************************************************/
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QFont>
#include <QBrush>
#include "mymodel.h"

mymodel::mymodel(QObject *parent):QAbstractTableModel(parent), 
    Row(3), Col(3)
{
    for(int row = 0;row < Row;row++ )
    {
        for(int col = 0;col < Col;col++)
        {
            m_gridData[row][col] = "data";
        }
    }
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
    if(role == Qt::DisplayRole)
    {
       return m_gridData[index.row()][index.column()];
    }

    return QVariant();
}

QVariant mymodel::headerData(int section, Qt::Orientation orientation, int role)const 
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal){
            switch(section)
            {
                case 0:
                    return 1;
                case 1:
                    return 2;
                case 2:
                    return 3;
            }
        }
    }
    if(role == Qt::EditRole)
    {
        return 99;
    }
    return QVariant();
}

bool mymodel::setData(const QModelIndex & index, const QVariant & value,
            int role)
{
    QString result;
    if(role == Qt::EditRole)
    {
        if(!value.toString().isEmpty())
        {
            m_gridData[index.row()][index.column()] = value.toString();
            qDebug()<<value.toString();
        }
        result = value.toString();
//        for(int row = 0; row < 3;row++)
//        {
//            for(int col = 0;col < 3;col++)
//            {
//                result += m_gridData[row][col] = ' ';
//            }
//        }
    emit editComplete(result);
    }
    return true;
}
Qt::ItemFlags mymodel::flags(const QModelIndex &index)const 
{
    return Qt::ItemIsEditable|QAbstractTableModel::flags(index);
}
