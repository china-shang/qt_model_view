/*************************************************************************
    > File Name: mainwindow.h
    > Created Time: 2017年02月28日 星期二 13时51分37秒
 ************************************************************************/
#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QTableView>
#include <QMainWindow>
#include "mymodel.h"
#include "mydelegate.h"

class mainwindow:public QMainWindow
{
    Q_OBJECT
public:
    mainwindow(QWidget *parent = 0);
private:
    mymodel *model;
    QTableView *view;
    mydelegate *delegate;
};





#endif
