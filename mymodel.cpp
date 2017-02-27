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

mymodel::mymodel(QObject *parent):QAbstractTableModel(parent)
{
    auto timer = new QTimer(this);
    timer->setInterval(1000);
    
    connect(timer,SIGNAL(timeout()), this,SLOT(timerHit()));;
    timer->start();
}

void mymodel::timerHit()
{
    QModelIndex index = createIndex(1, 1);
    emit dataChanged(index, index);
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

    if(role == Qt::DisplayRole)
    {
        if(row == 1 && col == 1)
        {
            return QTime::currentTime().toString();
        }
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
                    return QString("first");
                case 1:
                    return QString("second");
                case 2:
                    return QString("third");
            }
        }
    }
    return QVariant();
}
