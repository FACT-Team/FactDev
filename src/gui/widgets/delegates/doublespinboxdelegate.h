#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QItemDelegate>
#include <QDoubleSpinBox>

namespace Gui {
namespace Widgets {
namespace Delegates {

/**
 * @author Florent Berbie
 * @brief The DoubleSpinBoxDelegate class
 */
class DoubleSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    /**
     * @brief DoubleSpinBoxDelegate::DoubleSpinBoxDelegate
     * @param parent
     */
    DoubleSpinBoxDelegate(QObject *parent = 0);

    /**
     * @brief DoubleSpinBoxDelegate::createEditor Return a ComboBox specified
     * by <i>index</i> item defined by the <i>parent</i> widget and style
     * <i>option</i> which are used to control how the editor widgets appears
     * @param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     * @return DoubleSpinBoxDelegate
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    /**
     * @brief DoubleSpinBoxDelegate::setEditorData Sets the data to be
     *  displayed and edited by the <i>editor</i> from the data model item
     *  specified by the model <i>index</i>
     * @param editor Data edited
     * @param index Index of the model to edit
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    /**
     * @brief DoubleSpinBoxDelegate::setEditorData Sets the data to be
     *  displayed and edited by the <i>editor</i> from the data model item
     *  specified by the model <i>index</i>
     * @param editor Data edited
     * @param index Index of the model to edit
     */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const;

    /**
     * @brief DoubleSpinBoxDelegate::updateEditorGeometry Update the
     *  <i>editor</i> for the item specified by <i>index</i> according to the
     *  style <i>option</i> given.
     * @param editor Editor widget to update
     * @param option Style option
     * @param index Item index
     */
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

}
}
}
#endif // SPINBOXDELEGATE_H
