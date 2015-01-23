#ifndef CHECKQLINEEDIT_H
#define CHECKQLINEEDIT_H

#include <QLineEdit>
#include <QPushButton>
#include "ICheckField.h"

/**
 * @brief The CheckQLineEdit class LineEdit custom with a check of text inputed
 */
class CheckQLineEdit : public QLineEdit, public ICheckField
{
    Q_OBJECT
public:
    /**
     * @brief CheckQLineEdit::CheckQLineEdit Construct a CheckQLineEdit
     * @param parent
     */
    explicit CheckQLineEdit(QWidget *parent = 0, QPushButton* btn=0);

    /**
     * @brief CheckQLineEdit::displayCheckValidFieldIcon Display a valid icon
     * into the field
     */
    void displayCheckValidFieldIcon();

    /**
     * @brief CheckQLineEdit::displayCheckNoValidFieldIcon Display a "no valid"
     * icon into the field
     */
    void displayCheckNoValidFieldIcon();

    /**
     * @brief CheckQLineEdit::getBtnValid
     * @return a
     */
    QPushButton *getBtnValid() const;
    /**
     * @brief CheckQLineEdit::setBtnValid
     * @param getBtnValid
     */
    void setBtnValid(QPushButton *getBtnValid);

    /**
     * @brief isValid Return true if the current field if valid
     * @return boolean
     */
    bool isValid();
signals:

public slots:
    /**
     * @brief CheckQLineEdit::fieldTextChanged For each new characater inputed
     * or removed, displays an icon to show if the field is valid or not
     */
    void fieldTextChanged(const QString &);

private:
    QPushButton* _btnValid;


};

#endif // CHECKQLINEEDIT_H
