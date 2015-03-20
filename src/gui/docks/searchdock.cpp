#include "searchdock.h"
#include "ui_searchdock.h"

namespace Gui {
namespace Docks {
SearchDock::SearchDock(QWidget* parent, Qt::WindowFlags flags) : QDockWidget(parent, flags), ui(new Ui::SearchDock)

{
    ui->setupUi(this);
}

SearchDock::~SearchDock()
{
    delete ui;

}

void SearchDock::search(QString text)
{
    Models::Search s;
    QString styleSearchBackground =
    "background: url(:/icons/searchMini);"
    "background-position: right;"
    "background-repeat: no-repeat; "
    "border-radius: 0px;"
    "height: 23px;"
    "border: 1px solid #bbb;";
    QString styleSearchNoBackground =
    "border-radius: 0px;"
    "height: 23px;"
    "border: 1px solid #bbb;";
    if(ui->leSearch->text() != "") {
    ui->leSearch->setStyleSheet(styleSearchNoBackground);
    } else {
        ui->leSearch->setStyleSheet(styleSearchBackground);
    }
    s.setGroupFilter(ui->gpbxSearchFilter->isChecked());
    s.setSearchInCompanies(ui->chkSearchCompany->isChecked());
    s.setSearchInReferentLastname(ui->chkReferentName->isChecked());
    s.setSearchInProjects(ui->chkProjectName->isChecked());
    s.setSearchInContributories(ui->chkContributory->isChecked());
    s.setSearchInBillsQuotes(ui->chkBillQuote->isChecked());
    s.setText(text);

    emit textChanged(s.getFilter());
}


}
}
