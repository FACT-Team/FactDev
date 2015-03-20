#ifndef TEXGENERATOR_H
#define TEXGENERATOR_H

#include "models/billing.h"
#include "models/user.h"

#include "libs/qt-mustache/src/mustache.h"

namespace Generator {
/**
 * @brief The TexGenerator class Generate a LaTeX file
 */
class TexGenerator
{
public:
    /**
     * @brief TexGenerator::TexGenerator Construct a TexGenerator
     * @param tpl Template LaTeX to apply
     */
    TexGenerator(QString tpl);
    ~TexGenerator();

    /**
     * @brief TexGenerator::generate Generate a LaTeX file into a file specified
     *  by the <i>path</i> and which contains <i>data</i>
     * @param data Data to integrate in the file
     * @param path Path of the out file
     */
    void generate(QVariantHash data, QString path);

private:
    QString _tplFile;   //!< Template to use
};

}
#endif // TEXGENERATOR_H
