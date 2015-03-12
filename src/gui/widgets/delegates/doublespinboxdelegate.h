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
     * @brief DoubleSpinBoxDelegate::createEditor
     * @param parent
     * @param option
     * @param index
     * @return
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    /**
     * @brief DoubleSpinBoxDelegate::setEditorData
     * @param editor
     * @param index
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    /**
     * @brief DoubleSpinBoxDelegate::setModelData
     * @param editor
     * @param model
     * @param index
     */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const;

    /**
     * @brief DoubleSpinBoxDelegate::updateEditorGeometry
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
#endif // SPINBOXDELEGATE_H
