#ifndef CHECKQLINEEDIT_H
#define CHECKQLINEEDIT_H

#include <QLineEdit>
#include "ICheckField.h"

class CheckQLineEdit : public QLineEdit, public ICheckField
{
    Q_OBJECT
public:
    explicit CheckQLineEdit(QWidget *parent = 0);

signals:

public slots:
    void textChanged(const QString &);
};

#endif // CHECKQLINEEDIT_H
