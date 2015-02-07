#include "generator.h"
#include "models/user.h"
#include "libs/qt-mustache/src/mustache.h"

Generator::Generator(Models::Billing* b)
{
    _billing = b;
}

Generator::~Generator()
{

}

void Generator::generate()
{
    QString ret;

    QFile file(":/tpl/billingtpl");
    if(file.open(QFile::ReadOnly|QFile::Text)) {
        QTextStream stream(&file);
        QVariantHash data;
        QString contactTemplate = stream.readAll();
        contactTemplate.remove(contactTemplate.count()-1, contactTemplate.count()); // Remove last \n
        Models::User u = Models::User(1);
        data["userFirstName"] = u.getFirstname();
        data["userLastName"] = u.getLastname();
        data["userTitle"] = u.getTitle();

        Mustache::Renderer renderer;
        Mustache::QtVariantContext context(data);

        ret  = renderer.render(contactTemplate, &context);

    }
    qDebug() << ret;
}


Models::Billing* Generator::getBilling() const
{
    return _billing;
}

void Generator::setBilling(Models::Billing* billing)
{
    _billing = billing;
}


