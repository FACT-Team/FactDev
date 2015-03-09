#ifndef PDFGENERATOR_H
#define PDFGENERATOR_H
#include <QString>
#include <QProcess>
#include <QFile>

namespace Generator {
class PdfGenerator
{
public:
    PdfGenerator(QString pdflatexPath="pdflatex");
    void generate(QString inputDir, QString filename);
private:
    QString _pdflatexPath;
};
}
#endif // PDFGENERATOR_H
