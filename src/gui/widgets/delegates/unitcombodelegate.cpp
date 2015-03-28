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
    QComboBox* editor = new QComboBox(parent);
    editor->addItem("Heures", QVariant(0));
    editor->addItem("Jours", QVariant(1));

    return editor;
}



void UnitComboDelegate::paint(QPainter *painter,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const
{
    QStyleOptionViewItemV4 myOption = option;
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QString text = value == 1 ? "Jours" : "Heures";
    myOption.text = text;

    QApplication::style()->drawControl(QStyle::CE_ItemViewItem,
                                       &myOption,
                                       painter);
}

}
}
}
