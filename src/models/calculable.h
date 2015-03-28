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

    /**
     * @brief ContributoriesList::getSumQuantity Return the sum of quantity
     * (number of days) of the Contributories
     * @return sum of quantity in days
     */
    virtual double getSumQuantity() = 0;

};

}
#endif // CALCULABLE_H
