#include "double.h"
namespace Utils {
double Double::round(double n, unsigned int d)
{
    return std::floor(n * pow(10, d)+ 0.5)/pow(10, d);
}

}
