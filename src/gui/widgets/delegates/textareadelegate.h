#ifndef TEXTAREADELEGATE_H
#define TEXTAREADELEGATE_H

#include <QItemDelegate>
#include <QTextEdit>

namespace Gui {
namespace Widgets {
namespace Delegates {

/**
 * @author Antoine de Roquemaurel
 * @brief The TextareaDelegate class
 */

class TextareaDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    /**
     * @brief TextareaDelegate::TextareaDelegate
     * @param parent
     */
    TextareaDelegate(QWidget* parent=0);

    /**
     * @brief TextareaDelegate::setModelData Sets the data model from content in editor
     * @param editor Data edited
     * @param index Index of the model to edit
     */
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    /**
     * @brief TextareaDelegate::updateEditorGeometry Update the
     *  <i>editor</i> for the item specified by <i>index</i> according to the
     *  style <i>option</i> given.
     * @param editor Editor widget to update
     * @param option Style option
     * @param index Item index
     */
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const;

    /**
     * @brief TextareaDelegate::createEditor Return a QTextEdit specified
     * by <i>index</i> item defined by the <i>parent</i> widget and style
     * <i>option</i> which are used to control how the editor widgets appears
     * @param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     * @return TextareaDelegate
     */
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const;

    /**
     * @brief TextareaDelegate::setEditorData Sets the data to be
     *  displayed and edited by the <i>editor</i> from the data model item
     *  specified by the model <i>index</i>
     * @param editor Data edited
     * @param index Index of the model to edit
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
};

}
}
}
#endif // TEXTAREADELEGATE_H
