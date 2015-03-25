#include "chosedirectorywidget.h"
#include "ui_chosepathwidget.h"

namespace Gui {
namespace Widgets {
namespace Path {
ChoseDirectoryWidget::ChoseDirectoryWidget(QWidget *parent) :
    ChosePathWidget(parent)
{
    ui->setupUi(this);
}

void ChoseDirectoryWidget::fillField()
{
    ui->url->setText(QFileDialog::getExistingDirectory(this, ("Choisir un répertoire de travail"), getDefaultLocation()));
}

}
}
}
