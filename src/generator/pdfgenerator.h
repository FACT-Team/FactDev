#ifndef PDFGENERATOR_H
#define PDFGENERATOR_H
#include <QString>
#include <QProcess>
#include <QFile>

namespace Generator {
/**
 * @brief The PdfGenerator class Generator of PDF files
 */
class PdfGenerator
{
public:
    /**
     * @brief PdfGenerator::PdfGenerator Construct a PdfGenerator
     * @param pdflatexPath Path to the command to generate PDF file
     */
    PdfGenerator(QString pdflatexPath="pdflatex");

    /**
     * @brief PdfGenerator::generate Generate a PDF of the file named
     * <i>filename</i> into the directory <i>inputDir</i>
     * @param inputDir Directory where is store the PDF generated
     * @param filename File name
     */
    void generate(QString inputDir, QString filename);
private:
    QString _pdflatexPath;
};
}
#endif // PDFGENERATOR_H
