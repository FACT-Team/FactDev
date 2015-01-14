#include "customercontextualmenu.h"

CustomerContextualMenu::CustomerContextualMenu(QWidget* widget)  :QMenu(widget)
{
    QIcon icon;
//    icon.addFile(QStringLiteral(":/icones/pdf"), QSize(), QIcon::Normal, QIcon::Off);
    _removeAction = new QAction("Supprimer le client", widget);
  //  icon.addFile(QStringLiteral(":/icones/pdf"), QSize(), QIcon::Normal, QIcon::Off);
    _editAction = new QAction("Editer le client", widget);
    //icon.addFile(QStringLiteral(":/icones/pdf"), QSize(), QIcon::Normal, QIcon::Off);
    _openAction = new QAction("Ouvrir le client", widget);

    addAction(_openAction);
    addAction(_editAction);
    addAction(_removeAction);

}

CustomerContextualMenu::~CustomerContextualMenu()
{
    delete _openAction;
    delete _editAction;
    delete _removeAction;
}

