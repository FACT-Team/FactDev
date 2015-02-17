#include "projectcombodelegate.h"
#include "database/projectdatabase.h"
namespace Gui {
namespace Widgets {
namespace Delegates {

ProjectComboDelegate::ProjectComboDelegate(QSharedPointer<Models::Customer> c, QObject *parent) : QItemDelegate(parent)
{
    _projects = Databases::ProjectDatabase::instance()->getProjectsOfCustomer(c);
}


ProjectComboDelegate::~ProjectComboDelegate()
{

}

QWidget *ProjectComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
    QComboBox* editor = new QComboBox(parent);
    QMap<int, Models::Project> buff = _projects;

    for(int key : _removeInCombo) {
        buff.remove(key);
    }

    for(Models::Project p : buff.values()) {
        editor->addItem(p.getName(), QVariant(p.getId()));
    }

    return editor;
}

void ProjectComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    int value = index.model()->data(index, Qt::EditRole).toUInt();
    for(int i = 0 ; i < comboBox->count() ; ++i) {
        if(comboBox->itemData(i) == value) {
            comboBox->setCurrentIndex(i);
            break;
        }
    }

}

void ProjectComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->itemData(comboBox->currentIndex()), Qt::EditRole);
}

void ProjectComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

void ProjectComboDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItemV4 myOption = option;
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QString text = _projects[value].getName();
    myOption.text = text;

    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}

void ProjectComboDelegate::removeInCombo(QList<int> &l)
{
    _removeInCombo = l;
}
}
}
}
