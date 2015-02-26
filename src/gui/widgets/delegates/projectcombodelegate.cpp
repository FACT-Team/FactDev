#include "projectcombodelegate.h"
#include "database/projectdatabase.h"
namespace Gui {
namespace Widgets {
namespace Delegates {

ProjectComboDelegate::ProjectComboDelegate(QSharedPointer<Models::Customer> c, QObject *parent) : ComboBoxDelegate(parent)
{
    _projects = Databases::ProjectDatabase::instance()->getProjectsOfCustomer(c);
    _locked = false;
}

QWidget *ProjectComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */,
                                            const QModelIndex & index) const
{
    if(_locked && index.model()->data(index, Qt::EditRole).toUInt() != 0) {
        return 0;
    }

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
QMap<int, Models::Project> ProjectComboDelegate::getProjects() const
{
    return _projects;
}

void ProjectComboDelegate::setLocked(bool locked)
{
    _locked = locked;
}

bool ProjectComboDelegate::getLocked() const
{
    return _locked;
}

}
}
}
