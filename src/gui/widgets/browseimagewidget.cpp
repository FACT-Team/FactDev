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
}

BrowseImageWidget::~BrowseImageWidget()
{
    delete ui;
}

void BrowseImageWidget::setImageScaled(QString path, int width, int height)
{
    _img.load(path);
    _img.scaled(width,height,Qt::KeepAspectRatio);
}

QPixmap BrowseImageWidget::getImage()
{
    return _img;
}

void BrowseImageWidget::setImage(const QPixmap &img)
{
    _img = img;
    ui->lbIcon->setPixmap(_img);
}


void BrowseImageWidget::browseImagePath()
{    
    QString file = QFileDialog::getOpenFileName(
                this,
                tr("Ouvrir une image"),
                "",
                tr("Images (*.png *.xpm *.jpg)"));
    QFileInfo fileInfo(file);
    setImageScaled(fileInfo.filePath());
    ui->lbIcon->setPixmap(_img);
    _extension =  Utils::String::getExtensionFile(fileInfo.fileName());
}
QString BrowseImageWidget::getExtension() const
{
    return _extension;
}

}
}
