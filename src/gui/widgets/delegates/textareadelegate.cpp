#include "textareadelegate.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

TextareaDelegate::TextareaDelegate(QWidget* parent) : QItemDelegate(parent)

{
}

QWidget *TextareaDelegate::createEditor(QWidget *parent,
                                             const QStyleOptionViewItem &,
                                             const QModelIndex &) const
{
    QTextEdit* editor = new QTextEdit(parent);
    return editor;
}

void TextareaDelegate::setEditorData(
        QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    QTextEdit *textEdit = static_cast<QTextEdit*>(editor);
    textEdit->setText(value);
}

void TextareaDelegate::updateEditorGeometry(
        QWidget *editor,
        const QStyleOptionViewItem &option,
        const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

void TextareaDelegate::setModelData(QWidget *editor,
                                         QAbstractItemModel *model,
                                         const QModelIndex &index) const
{
    QTextEdit *textEdit = static_cast<QTextEdit*>(editor);
    QString value = textEdit->toPlainText();

    model->setData(index, value, Qt::EditRole);
}




}
}
}
