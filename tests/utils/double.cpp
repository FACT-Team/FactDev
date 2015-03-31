#include "double.h"
namespace Utils {
double Double::round(double n, unsigned int d)
{
    return floor(n * pow(10., d) + .5) / pow(10., d);
}

}
