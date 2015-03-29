#ifndef DOUBLE_H
#define DOUBLE_H
#include <math.h>

namespace Utils {

/**
 * @brief The Double class Utils functions for Double calculs
 */
class Double
{
public:
    /**
     * @brief round Roud a double value to d decimals
     * @param n The number
     * @param d The number of decimals who you want
     * @return The rounded value
     */
    static double round(double n, unsigned int d);
};
}
#endif // DOUBLE_H
