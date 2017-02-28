/*************************************************************************
    > File Name: mainwindow.cpp
    > Created Time: 2017年02月28日 星期二 14时03分55秒
 ************************************************************************/

#include "mainwindow.h"
mainwindow::mainwindow(QWidget *parent)
    :QMainWindow(parent), model(new mymodel(0)), view(new QTableView(this))
{
    view->setModel(model);
    setCentralWidget(view);
}

