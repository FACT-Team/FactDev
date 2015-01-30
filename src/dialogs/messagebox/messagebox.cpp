#include "messagebox.h"
#include "ui_messagebox.h"

MessageBox::MessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageBox)
{
    ui->setupUi(this);
}

MessageBox::~MessageBox()
{
    delete ui;
}

void MessageBox::aboutFact()
{
    MessageBox m;
    m.test();
    m.show();
    m.exec();

}

void MessageBox::test() {
    setImage(":/icons/img/FACT_official_square.png");
    setText(
        "Fact est une équipe de Développement créée dans le cadre de "
        "projets pour l'Université Toulouse III - Paul Sabatier. <br />"
        "Cette équipe est composée de : "
          "<ul>"
               "<li>Florent Berbie</li>"
               "<li>Manantsoa Andriamihary Razanbajatovo</li>"
               "<li>Cédric Rohaut</li>"
               "<li>Antoine de Roquemaurel</li>"
          "</ul>"
        "<br/><br/>"
        "Plus d'informations sur <a href=\"http://fact-team.github.io/\">http://fact-team.github.io/</a>");
}

void MessageBox::setImage(QString img, int width, int height) {
    QPixmap icon(img);
    icon.scaled(QSize(width,height), Qt::KeepAspectRatio);
    ui->lbIcon->setPixmap(icon);
}

void MessageBox::setText(QString txt) {
    ui->lbText->setText(txt);
}

