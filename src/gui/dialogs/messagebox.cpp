#include "messagebox.h"
#include "ui_messagebox.h"

namespace Gui {
namespace Dialogs {
MessageBox::MessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageBox)
{
    ui->setupUi(this);
}

MessageBox::~MessageBox() {
    delete ui;
}

void MessageBox::showAboutFact() {
    MessageBox m;
    m.aboutFact();
    m.exec();

}

void MessageBox::showAboutFactDev () {
    MessageBox m;
    m.aboutFactDev();
    m.exec();

}

void MessageBox::showAboutIcons() {
    MessageBox m;
    m.aboutIcons();
    m.exec();

}

void MessageBox::aboutFact() {
    setWindowTitle("À propos de l'équipe FACT");
    setImage(":/icons/img/FACT_official_square.png");
    setText(
        "FACT est une équipe de Développement créée dans le cadre de <br/>"
        "projets pour l'Université Toulouse III - Paul Sabatier. <br />"
        "Cette équipe est composée de : "
          "<ul>"
               "<li><b>F</b>lorent Berbie</li>"
               "<li><b>A</b>ntoine de Roquemaurel</li>"
                "<li><b>C</b>édric Rohaut</li>"
               "<li>Manan<b>T</b>soa Andriamihary Razanbajatovo</li>"
          "</ul>"
        "<br/><br/>"
        "Plus d'informations sur <a href=\"http://fact-team.github.io/\">"
        "http://fact-team.github.io/</a>");
}

void MessageBox::aboutFactDev()
{
    setWindowTitle("À propos de FactDev");
    setImage(":/icons/FactDev");
    setText(
        "<p>FactDev est un logiciel de Facture et Devis développé par <br/>"
        "l'équipe FACT dans le cadre de l'UE Projet pour l'Université <br/>"
        "Toulouse III - Paul  Sabatier.<br/></p>"
        "<p>"
       // "Ce logiciel est libre et sous license *****. "
        "<br/>Le code source est disponible sur Github :"
        "<br/><a href=\"https://github.com/FACT-Team/FactDev\">"
        "https://github.com/FACT-Team/FactDev</a></p>");
}

void MessageBox::aboutIcons()
{
    setWindowTitle("À propos des icones");
    setImage(":/icons/FactDev");
    setText(
        "Le pack d'icons à été développé par Florent Berbie pour l'usage <br/>"
        "du logiciel FactDev.");
}

void MessageBox::setImage(QString img, int width, int height) {
    QPixmap icon(img);
    icon.scaled(QSize(width,height), Qt::KeepAspectRatio);

    ui->lbIcon->setPixmap(icon);
    ui->lbIcon->setScaledContents(true);
}

void MessageBox::setText(QString txt) {
    ui->lbText->setText(txt);
}

}
}
