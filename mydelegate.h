/*************************************************************************
    > File Name: mydelegate.h
    > Created Time: 2017年03月05日 星期日 20时32分06秒
 ************************************************************************/
#ifndef _MYDELEGATE_H
#include <QStyledItemDelegate>
class mydelegate:public QStyledItemDelegate
{
    Q_OBJECT
public:
    mydelegate(QWidget *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, 
                         const QModelIndex &index)const;
    void setEditorDate(QWidget *editor, const QModelIndex &index)const;
    void setModelDate(QWidget *editor, QAbstractItemModel *model, 
                     const QModelIndex &index)const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, 
                             const QModelIndex &index)const;

};

#define _MYDELEGATE_H
#endif
