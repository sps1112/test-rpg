#ifndef MATHENGINE_H
#define MATHENGINE_H

#include <iostream>
#include <cmath>

namespace rpgText
{
    // Get Maximum of a and b
    float Max(float a, float b);

    // Gets Minimum of a and b
    float Min(float a, float b);

    // Clamps the value of num between min and max
    float Clamp(float min, float max, float num);
} // namespace rpgText

#endif