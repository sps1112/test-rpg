#include "MathEngine.h"

namespace rpgText
{
    float max(float a, float b)
    {
        return (a > b) ? a : b;
    }

    float min(float a, float b)
    {
        return (a < b) ? a : b;
    }

    float clamp(float num, float min, float max)
    {
        return (num > max) ? (max) : ((num < min) ? (min) : (num));
    }

} // namespace rpgText
