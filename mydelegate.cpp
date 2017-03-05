/*************************************************************************
    > File Name: mydelegate.cpp
    > Created Time: 2017年03月05日 星期日 20时36分10秒
 ************************************************************************/

#include <QSpinBox>
#include "mydelegate.h"
mydelegate::mydelegate(QWidget *parent):
    QStyledItemDelegate(parent)
{

}
QWidget *mydelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, 
                     const QModelIndex &index)const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}
void mydelegate::setEditorDate(QWidget *editor, const QModelIndex &index)const
{

    int value = index.model()->data(index, Qt::EditRole).toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);

}
void mydelegate::setModelDate(QWidget *editor, QAbstractItemModel *model, 
                 const QModelIndex &index)const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}
void mydelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, 
                         const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}
