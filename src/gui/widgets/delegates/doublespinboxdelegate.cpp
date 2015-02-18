#include "doublespinboxdelegate.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}
QWidget *DoubleSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    QDoubleSpinBox* editor = new QDoubleSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(10000);
    editor->setSingleStep(0.5);
    return editor;
}
void DoubleSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toInt();

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}

void DoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

void DoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    double value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

}
}
}
