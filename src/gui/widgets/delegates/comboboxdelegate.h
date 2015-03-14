#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H
#include <QItemDelegate>
#include <QComboBox>
#include <QApplication>

namespace Gui {
namespace Widgets {
namespace Delegates {

/**
 * @author Antoine de Roquemaurel
 * @brief The ComboBoxDelegate class
 */
class ComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    /**
     * @brief ComboBoxDelegate::ComboBoxDelegate Construct a ComboBoxDelegate
     * @param parent Object parent
     */
    ComboBoxDelegate(QObject* parent=0);

    /**
     * @brief ComboBoxDelegate::createEditor Return a ComboBox specified by
     * <i>index</i> item defined by the <i>parent</i> widget and style
     * <i>option</i> which are used to control how the editor widgets appears
     * @param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     * @return ComboBox
     */
    virtual QWidget *createEditor(
            QWidget *parent,
            const QStyleOptionViewItem &option,
            const QModelIndex &index) const = 0;

    /**
     * @brief ComboBoxDelegate::paint Renders the delegate using the given
     * <i>painter</i> and style <i>option</i> for the item specified by
     * <i>index</i>
     *@param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     */
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const = 0;

    /**
     * @brief ComboBoxDelegate::setEditorData Sets the data to be displayed and
     *  edited by the <i>editor</i> from the data model item specified by the
     * model <i>index</i>
     * @param editor Data edited
     * @param index Index of the model to edit
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    /**
     * @brief ComboBoxDelegate::setModelData Gets data from the <i>editor</i>
     * widget and stores it in the specified <i>model</i> at the item
     *  <i>index</i>
     * @param editor Editor Widget
     * @param model Model to store data
     * @param index Item index
     */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const;

    /**
     * @brief ComboBoxDelegate::updateEditorGeometry Update the <i>editor</i>
     * for the item specified by <i>index</i> according to the style
     * <i>option</i> given.
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
#endif // COMBOBOXDELEGATE_H
