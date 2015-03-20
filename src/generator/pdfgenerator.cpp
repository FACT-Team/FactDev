#include "pdfgenerator.h"

namespace Generator {
PdfGenerator::PdfGenerator(QString pdflatexPath)
{
    _pdflatexPath = pdflatexPath;
}

void PdfGenerator::generate(QString inputDir, QString filename)
{
    QProcess process;
    process.setWorkingDirectory(inputDir);
    QStringList args;
    args << filename+".tex";
    process.start(_pdflatexPath, args);
    process.waitForFinished();


    QFile(inputDir+"/"+filename+".aux").remove();
    QFile(inputDir+"/"+filename+".log").remove();
}

}
