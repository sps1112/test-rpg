#include "MathEngine.h"

namespace rpgText
{
    // Get Maximum of a and b
    float max(float a, float b)
    {
        return (a > b) ? a : b;
    }

    // Get Minimum of a and b
    float min(float a, float b)
    {
        return (a < b) ? a : b;
    }

    // Clamps the value of num between min and max
    float clamp(float num, float min, float max)
    {
        return (num > max) ? (max) : ((num < min) ? (min) : (num));
    }
} // namespace rpgText
