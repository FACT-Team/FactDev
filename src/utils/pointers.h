#ifndef POINTERS_H
#define POINTERS_H

#include <QObject>

namespace Utils {
/**
 * @author Antoine de Roquemaurel
 * @brief The pointers class
 */
class pointers
{
public:
    /**
     * @brief pointers::deleteIfNotNull Remove to the memory the object <i>p</i>
     *  if it is not null
     * @param p An object
     */
    static void deleteIfNotNull(QObject* p);
};
}
#endif // POINTERS_H
