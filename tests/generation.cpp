#include "generation.h"

#include "libs/qt-mustache/src/mustache.h"
#include <QTextStream>

Generation::Generation()
{
}

void Generation::testTemplate()
{
    QVariantHash contact;
    contact["name"] = "John Smith";
    contact["email"] = "john.smith@gmail.com";

    QString contactTemplate = "<b>{{name}}</b> <a href=\"mailto:{{email}}\">{{email}}</a>";

    Mustache::Renderer renderer;
    Mustache::QtVariantContext context(contact);


    QVERIFY(renderer.render(contactTemplate, &context) == "<b>John Smith</b> <a href=\"mailto:john.smith@gmail.com\">john.smith@gmail.com</a>");

}

