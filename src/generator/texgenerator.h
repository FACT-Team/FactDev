#ifndef TEXGENERATOR_H
#define TEXGENERATOR_H

#include "models/billing.h"
#include "models/user.h"

#include "libs/qt-mustache/src/mustache.h"

namespace Generator {
class TexGenerator
{
public:
    TexGenerator(QString tpl);
    ~TexGenerator();

    void generate(QVariantHash data, QString path);

private:
    QString _tplFile;
};

}
#endif // TEXGENERATOR_H
