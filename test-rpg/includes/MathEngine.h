#ifndef MATHENGINE_H
#define MATHENGINE_H

// Standard Headers
#include <iostream>
#include <cmath>

namespace rpgText
{
    // Get Maximum of a and b
    float max(float a, float b);

    // Gets Minimum of a and b
    float min(float a, float b);

    // Clamps the value of num between min and max
    float clamp(float num, float min = 0.0f, float max = 1000.0f);

    // Checks if an event of "percent" chance occurs
    bool check_event(int percent);

} // namespace rpgText

#endif // !MATHENGINE_H
