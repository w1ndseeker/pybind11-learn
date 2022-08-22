#include "cppadd.h"

namespace ws
{
    float cppadd::sum(float &_a, float &_b)
    {
        return _a + _b;
    }

    float cppadd::sum()
    {
        return a + b;
    }

    cppadd::cppadd(float _a, float _b) : a(_a), b(_b){};

} // namespace ws
