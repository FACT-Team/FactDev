#include "generator/texgenerator.h"

namespace Generator {
TexGenerator::TexGenerator(QString tpl)
{
    _tplFile = tpl;
}

TexGenerator::~TexGenerator()
{

}

void TexGenerator::generate(QVariantHash data, QString path)
{
    QString ret;

    QFile file(_tplFile);
    if(file.open(QFile::ReadOnly|QFile::Text)) {
        QTextStream stream(&file);
        QString contactTemplate = stream.readAll();


        Mustache::Renderer renderer;
        Mustache::QtVariantContext context(data);

        ret  = renderer.render(contactTemplate, &context);
        file.close();
    }

    QFile out(path);
    if(out.open(QFile::WriteOnly|QFile::Text)) {
        QTextStream fout(&out);
        fout << ret;
        out.close();
    }
}

}
