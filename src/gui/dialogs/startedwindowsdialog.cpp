#include "startedwindowsdialog.h"
#include "ui_startedwindowsdialog.h"

StartedWindowsDialog::StartedWindowsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartedWindowsDialog)
{
    ui->setupUi(this);
}

StartedWindowsDialog::~StartedWindowsDialog()
{
    delete ui;
}
