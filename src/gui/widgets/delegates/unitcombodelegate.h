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
     * @brief UnitComboDelegate::createEditor Return a ComboBox specified by
     * <i>index</i> item defined by the <i>parent</i> widget and style
     * <i>option</i> which are used to control how the editor widgets appears
     * @param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     * @return ComboBox
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    /**
     * @brief UnitComboDelegate::paint Renders the delegate using the given
     * <i>painter</i> and style <i>option</i> for the item specified by
     * <i>index</i>
     *@param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     */
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

};

}
}
}
#endif // UNITCOMBOBOXDELEGATE_H
