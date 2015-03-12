#ifndef UNITCOMBOBOXDELEGATE_H
#define UNITCOMBOBOXDELEGATE_H
#include <QWidget>
#include <QComboBox>
#include "gui/widgets/delegates/comboboxdelegate.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

/**
 * @brief The UnitComboDelegate class
 */
class UnitComboDelegate : public ComboBoxDelegate
{
    Q_OBJECT

public:
    /**
     * @brief UnitComboDelegate::UnitComboDelegate
     * @param parent
     */
    UnitComboDelegate(QObject* parent=0);

    /**
     * @brief UnitComboDelegate::createEditor
     * @param parent
     * @param option
     * @param index
     * @return
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    /**
     * @brief UnitComboDelegate::paint
     * @param painter
     * @param option
     * @param index
     */
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

};

}
}
}
#endif // UNITCOMBOBOXDELEGATE_H
