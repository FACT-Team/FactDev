#include "projectcombodelegate.h"
#include <QApplication>
ProjectComboDelegate::ProjectComboDelegate(QObject *parent) : QItemDelegate(parent)
{
    _projects  << "COUCOU" << "MACHIN" << "CHOSE";
}

ProjectComboDelegate::~ProjectComboDelegate()
{

}

QWidget *ProjectComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
  QComboBox* editor = new QComboBox(parent);
  for(unsigned int i = 0; i < _projects.count(); ++i)
    {
    editor->addItem(_projects[i]);
    }
  return editor;
}

void ProjectComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QComboBox *comboBox = static_cast<QComboBox*>(editor);
  int value = index.model()->data(index, Qt::EditRole).toUInt();
  comboBox->setCurrentIndex(value);
}

void ProjectComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QComboBox *comboBox = static_cast<QComboBox*>(editor);
  model->setData(index, comboBox->currentIndex(), Qt::EditRole);
}

void ProjectComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}

void ProjectComboDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItemV4 myOption = option;
  QString text = _projects[index.row()];

  myOption.text = text;

  QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}
