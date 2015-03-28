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
     * @brief getPrice Return the price of a calculable object
     * @return The price
     */
    virtual double getPrice(bool paied=false) = 0;
};

}
#endif // CALCULABLE_H
