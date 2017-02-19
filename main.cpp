/*************************************************************************
    > File Name: main.cpp
    > Created Time: 2017年02月18日 星期六 13时17分08秒
 ************************************************************************/
 #include <QtWidgets/QApplication>
 #include <QtWidgets/QTableView>
 #include "mymodel.h"
 int main(int argc, char *argv[])
 {
    QApplication app(argc, argv);
    QTableView tableView;
    mymodel myModel(0);
    tableView.setModel( &myModel );
    tableView.show();
    return app.exec();
 }

