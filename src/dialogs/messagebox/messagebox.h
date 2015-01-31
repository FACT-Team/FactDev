#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

namespace Ui {
class MessageBox;
}

class MessageBox : public QDialog
{
    Q_OBJECT

public:
    static const int ERROR = 0;     //!< constant value assigned to Customer
    static const int HELP = 1;      //!< constant value assigned to Project
    static const int INFO = 2;      //!< constant value assigned to Billing
    static const int WARNING = 3;   //!< constant value assigned to Quote
    explicit MessageBox(QWidget *parent = 0);
    ~MessageBox();

    void static showAboutFact();

    void static showAboutFactDev();

    void static showAboutIcons();

    void static showErrorMessage(QString title, QString message);

    void static showHelpMessage(QString title, QString message);

    void static showInformationMessage(QString title, QString message);

    void static showWarningMessage(QString title, QString message);

    void aboutFact();

    void aboutFactDev();

    void aboutIcons();

    void showMessage(QString title, QString message, int type);
    /*
    void errorMessage(QString title = "Message d'erreur", QString message);

    void helpMessage(QString title = "Aide", QString message);

    void informationMessage(QString title = "Message d'information",
                            QString message);

    void warningMessage(QString title = "Attention", QString message);
    */
    void setImage(QString img, int width = 128, int height = 128);

    void setText(QString txt);
private:
    Ui::MessageBox *ui;
};

#endif // MESSAGEBOX_H
