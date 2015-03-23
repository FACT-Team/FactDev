#ifndef TEXTAREADELEGATE_H
#define TEXTAREADELEGATE_H

#include <QItemDelegate>
#include <QTextEdit>

namespace Gui {
namespace Widgets {
namespace Delegates {

class TextareaDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    TextareaDelegate(QWidget* parent=0);
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
};

}
}
}
#endif // TEXTAREADELEGATE_H
