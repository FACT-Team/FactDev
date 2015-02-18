#include "comboboxdelegate.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

ComboBoxDelegate::ComboBoxDelegate(QObject *parent) : QItemDelegate(parent)
{

}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
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

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->itemData(comboBox->currentIndex()), Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

}
}
}
