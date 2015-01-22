#include "projectcombodelegate.h"
#include <QApplication>
#include <QDebug>
ProjectComboDelegate::ProjectComboDelegate(QObject *parent) : QItemDelegate(parent)
{
    Project a("Coucou");
    a.setId(0);
    Project b("test");
    b.setId(1);
    Project c("machin");
    c.setId(2);
    _projects.insert(0, a);
    _projects.insert(1, b);
    _projects.insert(2, c);
}

ProjectComboDelegate::~ProjectComboDelegate()
{

}

QWidget *ProjectComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
  QComboBox* editor = new QComboBox(parent);
  for(Project p : _projects.values())
    {
    editor->addItem(p.getName(), QVariant(p.getId()));
    }
  return editor;
}

void ProjectComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QComboBox *comboBox = static_cast<QComboBox*>(editor);
  int value = index.model()->data(index, Qt::EditRole).toUInt();
  for(int i = 0 ; i < comboBox->count() ; ++i) {
      if(comboBox->itemData(i) == value) {
          comboBox->setCurrentIndex(i);
          break;
      }
  }

}

void ProjectComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QComboBox *comboBox = static_cast<QComboBox*>(editor);
  model->setData(index, comboBox->itemData(comboBox->currentIndex()), Qt::EditRole);
}

void ProjectComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}

void ProjectComboDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItemV4 myOption = option;
  int value = index.model()->data(index, Qt::EditRole).toInt();
  QString text = _projects[value].getName();
  myOption.text = text;

  QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}
