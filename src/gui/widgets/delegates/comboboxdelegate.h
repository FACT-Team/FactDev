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
     * @brief ComboBoxDelegate::createEditor
     * @param parent
     * @param option
     * @param index
     * @return
     */
    virtual QWidget *createEditor(
            QWidget *parent,
            const QStyleOptionViewItem &option,
            const QModelIndex &index) const = 0;

    /**
     * @brief ComboBoxDelegate::paint
     * @param painter
     * @param option
     * @param index
     */
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const = 0;

    /**
     * @brief ComboBoxDelegate::setEditorData
     * @param editor
     * @param index
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    /**
     * @brief ComboBoxDelegate::setModelData
     * @param editor
     * @param model
     * @param index
     */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const;

    /**
     * @brief ComboBoxDelegate::updateEditorGeometry
     * @param editor
     * @param option
     * @param index
     */
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;

};

}
}
}
#endif // COMBOBOXDELEGATE_H
