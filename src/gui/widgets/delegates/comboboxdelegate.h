#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H
#include <QItemDelegate>
#include <QComboBox>
#include <QApplication>

namespace Gui {
namespace Widgets {
namespace Delegates {

class ComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ComboBoxDelegate(QObject* parent=0);
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const = 0;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const = 0;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

}
}
}
#endif // COMBOBOXDELEGATE_H
