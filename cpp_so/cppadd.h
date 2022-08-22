#pragma once

namespace ws
{
    class cppadd
    {
    private:
        /* data */
    public:
        cppadd() = default;
        cppadd(float _a, float _b);
        ~cppadd() = default;

        float sum(float &_a, float &_b);
        float sum();

    private:
        float a;
        float b;
    };

}