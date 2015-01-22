#ifndef PROJECTCOMBODELEGATE_H
#define PROJECTCOMBODELEGATE_H
#include <QItemDelegate>
#include <QComboBox>

#include "models/project.h"
class ProjectComboDelegate : public QItemDelegate
{
Q_OBJECT
public:
    ProjectComboDelegate(QObject* parent=0);
    ~ProjectComboDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;


private:
  QList<Project> _projects;
};

#endif // PROJECTCOMBODELEGATE_H
