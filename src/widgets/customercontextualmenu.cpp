#include "customercontextualmenu.h"

CustomerContextualMenu::CustomerContextualMenu(QWidget* widget)  :QMenu(widget)
{
    QIcon icon;
    icon.addFile(
        QStringLiteral(":/icons/minus"),
        QSize(),
        QIcon::Normal,
        QIcon::Off);
    _removeAction = new QAction("Supprimer le client", widget);
    _removeAction->setIcon(icon);
    icon.addFile(
        QStringLiteral(":/icons/edit"),
        QSize(),
        QIcon::Normal,
        QIcon::Off);
    _editAction = new QAction("Editer le client", widget);
    _editAction->setIcon(icon);
    icon.addFile(
        QStringLiteral(":/icons/open"),
        QSize(),
        QIcon::Normal,
        QIcon::Off);
    _openAction = new QAction("Ouvrir le client", widget);
    _openAction->setIcon(icon);

    addAction(_openAction);
    addAction(_editAction);
    addAction(_removeAction);
    //connect(_openAction, SIGNAL(triggered()), widget, SLOT(openCustomer()));
    connect(_editAction, SIGNAL(triggered()), widget, SLOT(editCustomer()));
    connect(_removeAction, SIGNAL(triggered()), widget, SLOT(removeCustomer()));
}

CustomerContextualMenu::~CustomerContextualMenu()
{
    delete _openAction;
    delete _editAction;
    delete _removeAction;
}

