#ifndef CHECKQLINEEDIT_H
#define CHECKQLINEEDIT_H

#include <QLineEdit>
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
    explicit CheckQLineEdit(QWidget *parent = 0);

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

signals:

public slots:
    /**
     * @brief CheckQLineEdit::fieldTextChanged For each new characater inputed
     * or removed, displays an icon to show if the field is valid or not
     */
    void fieldTextChanged(const QString &);




};

#endif // CHECKQLINEEDIT_H
