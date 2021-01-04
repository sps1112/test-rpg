#include "MathEngine.h"

namespace rpgText
{
    // Get Maximum of a and b
    float Max(float a, float b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

    // Get Minimum of a and b
    float Min(float a, float b)
    {
        if (a < b)
        {
            return a;
        }
        return b;
    }

    // Clamps the value of num between min and max
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
