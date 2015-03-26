#ifndef UTILS_H
#define UTILS_H

#include <QString>

namespace Utils {
/**
 * @brief The Utils class
 * @author Antoine de Roquemaurel
 */
class String
{
public:
    /**
     * @brief String::firstLetterToUpper Put the first letter of a string in
     * capslock
     * @param s The string to display
     * @return The new string with caps
     */
    static QString firstLetterToUpper(QString s);

    /**
     * @brief String::getExtensionFile Get the extension file of the file named
     * <i>fileName</i>
     * @param file File name
     * @return extension of file
     */
    static QString getExtensionFile(QString fileName);
};
}
#endif // UTILS_H
