#include "double.h"
namespace Utils {
double Double::round(double n, unsigned int d)
{
    return std::floor(n * 100 + 0.5)/100;
}

}
