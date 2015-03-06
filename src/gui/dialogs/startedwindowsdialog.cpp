#include "startedwindowsdialog.h"
#include "ui_startedwindowsdialog.h"

StartedWindowsDialog::StartedWindowsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartedWindowsDialog)
{
    ui->setupUi(this);
    ui->wdgStack->setCurrentIndex(0);
}

StartedWindowsDialog::~StartedWindowsDialog()
{
    delete ui;
}

void StartedWindowsDialog::nextToPage2()
{
    ui->wdgStack->setCurrentIndex(1);
}

void StartedWindowsDialog::nextToPage3()
{
    ui->wdgStack->setCurrentIndex(2);
}

void StartedWindowsDialog::saveSettings()
{

}
