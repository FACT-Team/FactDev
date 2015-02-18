#ifndef UNITCOMBOBOXDELEGATE_H
#define UNITCOMBOBOXDELEGATE_H
#include <QWidget>
#include <QComboBox>
#include "gui/widgets/delegates/comboboxdelegate.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

class UnitComboDelegate : public ComboBoxDelegate
{
    Q_OBJECT

public:
    UnitComboDelegate(QObject* parent=0);


    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

}
}
}
#endif // UNITCOMBOBOXDELEGATE_H
