#include "unitcombodelegate.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

UnitComboDelegate::UnitComboDelegate(QObject *parent)
{

}

QWidget *UnitComboDelegate::createEditor(QWidget *parent,
                                         const QStyleOptionViewItem &option,
                                         const QModelIndex &index) const
{
    return 0; // TODO, remove me for unit implementation
    if(index.model()->data(index, Qt::EditRole).toUInt() != 0) {
        return 0;
    }

    QComboBox* editor = new QComboBox(parent);
    editor->addItem("Jours");
    editor->addItem("Heures");

    return editor;
}



void UnitComboDelegate::paint(QPainter *painter,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const
{
    QStyleOptionViewItemV4 myOption = option;
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QString text = value == 0 ? "Jours" : "Heures";
    myOption.text = text;

    QApplication::style()->drawControl(QStyle::CE_ItemViewItem,
                                       &myOption,
                                       painter);
}

}
}
}
