#include "chosepathwidget.h"
#include "ui_chosepathwidget.h"
namespace Gui {
namespace Widgets {
namespace Path {
ChosePathWidget::ChosePathWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChosePathWidget)
{
    ui->setupUi(this);
}

ChosePathWidget::~ChosePathWidget()
{
    delete ui;
}

void ChosePathWidget::updateBtn()
{
    emit textChanged();
}

void ChosePathWidget::setField(QString text) {
    ui->url->setText(text);
}

QString ChosePathWidget::getField(void) {
    return ui->url->text();
}

QString ChosePathWidget::getDefaultLocation()
{
    return QDir::homePath();
}

}
}
}
