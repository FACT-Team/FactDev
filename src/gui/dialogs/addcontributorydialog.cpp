#include "addcontributorydialog.h"
#include "ui_addcontributorydialog.h"

namespace Gui {
namespace Dialogs {

AddContributoryDialog::AddContributoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContributoryDialog)
{
    ui->setupUi(this);
}

AddContributoryDialog::~AddContributoryDialog()
{
    delete ui;
}
}
}
