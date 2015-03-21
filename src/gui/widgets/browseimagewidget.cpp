#include "browseimagewidget.h"
#include "ui_browseimagewidget.h"
#include <QDebug>

namespace Gui {
namespace Widgets {
BrowseImageWidget::BrowseImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrowseImageWidget)
{

    ui->setupUi(this);
    ui->lbIcon->setPixmap(getImage(":/icons/img/company.png"));
}

BrowseImageWidget::~BrowseImageWidget()
{
    delete ui;
}

QPixmap BrowseImageWidget::getImage(QString path, int width, int height)
{
    QPixmap img(path);
    img.scaled(width,height,Qt::KeepAspectRatio);

    return img;
}

void BrowseImageWidget::browseImagePath()
{
    QDir path;
    QFileDialog fileWindow( this,
                            "Rechercher une image",
                            "",
                            "*");
    fileWindow.exec();
    path = fileWindow.directory();

    qDebug() << path.currentPath();
    ui->lbIcon->setPixmap(getImage(path.currentPath()));
}

}
}
