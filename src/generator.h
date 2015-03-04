#ifndef GENERATOR_H
#define GENERATOR_H
#include "models/billing.h"
#include "models/user.h"

#include "libs/qt-mustache/src/mustache.h"

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
