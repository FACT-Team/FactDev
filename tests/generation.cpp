#include "generation.h"

#include "libs/qt-mustache/src/mustache.h"
#include <QTextStream>

#include "generator/texgenerator.h"
#include "generator/pdfgenerator.h"

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

void Generation::testFileTemplate() {
    QFile file(":/tpl/generation");
    QVERIFY(file.open(QFile::ReadOnly|QFile::Text));
    QTextStream stream(&file);
    QVariantHash contact;

    QString contactTemplate = stream.readAll();
    contactTemplate.remove(contactTemplate.count()-1, contactTemplate.count()); // Remove last \n
    contact["name"] = "John Smith";
    contact["email"] = "john.smith@gmail.com";

    Mustache::Renderer renderer;
    Mustache::QtVariantContext context(contact);

    QVERIFY(renderer.render(contactTemplate, &context) == "<b>John Smith</b> <a href=\"mailto:john.smith@gmail.com\">john.smith@gmail.com</a>");

}

void Generation::GenerationSimpleBilling() {
    try {
        QLocale::setDefault(QLocale(QLocale::French));

        Generator::TexGenerator gen(":/tpl/billingtpl");
        gen.generate(Models::Billing(1).getDataMap(), "/tmp/test1.tex");
        QVERIFY(QFile("/tmp/test1.tex").exists());
        gen.generate(Models::Billing(10).getDataMap(), "/tmp/test10.tex");
        QVERIFY(QFile("/tmp/test10.tex").exists());
        gen.generate(Models::Billing(11).getDataMap(), "/tmp/test11.tex");
        QVERIFY(QFile("/tmp/test11.tex").exists());

        Models::Billing b;
        Contributory c;
        c.setHourlyRate(5);
        c.setQuantity(1);
        c.setUnit(Unit(HOUR));
        b.addContributory(c);
        c.getProject()->setCustomer(QSharedPointer<Customer>(new Customer(1)));
        gen.generate(b.getDataMap(), "/tmp/test.tex");
        QVERIFY(QFile("/tmp/test.tex").exists());
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}


void Generation::GenerationSimpleTexBillingWithModel() {
    QLocale::setDefault(QLocale(QLocale::French));

    Billing b(1);
    b.generateTex();
    //QVERIFY(QFile(b.getPath()+".tex").exists());

}

void Generation::GenerationBillingPdf() {
    QLocale::setDefault(QLocale(QLocale::French));

    try {
        QVERIFY(QFile("/tmp/test11.tex").exists());
        Generator::PdfGenerator gen;
        gen.generate("/tmp/", "test11");
//        QVERIFY(QFile("/tmp/test11.pdf").exists());
        QVERIFY(!QFile("/tmp/test11.aux").exists());
        QVERIFY(!QFile("/tmp/test11.log").exists());
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void Generation::GenerationSimplePdfBillingWithModel() {
    QLocale::setDefault(QLocale(QLocale::French));

    Billing b(1);
    b.generatePdf();
    //    QVERIFY(QFile(b.getPath()+".pdf").exists());
    //    QVERIFY(!QFile(b.getPath()+".log").exists());
    //    QVERIFY(!QFile(b.getPath()+".aux").exists());
}
