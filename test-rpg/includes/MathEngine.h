#ifndef MATHENGINE_H
#define MATHENGINE_H

#include <iostream>
#include <cmath>

namespace rpgText
{
    float Max(float a, float b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

    float Min(float a, float b)
    {
        if (a < b)
        {
            return a;
        }
        return b;
    }

    float Clamp(float min, float max, float num)
    {
        if (num > max)
        {
            return max;
        }
        if (num < min)
        {
            return min;
        }
        return num;
    }
} // namespace rpgText

#endif