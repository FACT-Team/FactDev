#include "chosefilewidget.h"
#include "ui_chosepathwidget.h"

namespace Gui {
namespace Widgets {
namespace Path {
ChoseFileWidget::ChoseFileWidget(QWidget* parent) :
    ChosePathWidget(parent)
{
    _typeFiles = "*";
}

void ChoseFileWidget::fillField()
{
    ui->url->setText(QFileDialog::getOpenFileName(
                         this, ("Choisir une image de votre signature"), getDefaultLocation(),
                         _typeFiles));
    ChosePathWidget::fillField();
}
QString ChoseFileWidget::getypeFiles() const
{
    return _typeFiles;
}

void ChoseFileWidget::setTypeFiles(const QString &typeFiles)
{
    // can be "Images files (*.png *.jpg *.gif)" for images in example.
    // Default *
    _typeFiles = typeFiles;
}

}
}
}
