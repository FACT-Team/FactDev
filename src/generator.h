#ifndef GENERATOR_H
#define GENERATOR_H
#include "models/billing.h"

class Generator
{
public:
    Generator(QString tpl);
    ~Generator();

    void generate(QVariantHash data, QString path);

private:
    QString _tplFile;
};

#endif // GENERATOR_H
