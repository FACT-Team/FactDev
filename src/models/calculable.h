#ifndef CALCULABLE_H
#define CALCULABLE_H

namespace Models {

/**
 * @brief The Calculable interface Models who are calculable
 */
class Calculable
{
public:
    /**
     * @brief getRate Return the rate of a calculable object
     * @return The rate
     */
    virtual double getRate(bool paied=false) = 0;
};

}
#endif // CALCULABLE_H
