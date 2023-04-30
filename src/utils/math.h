/**
 * @file math.h
 * @author Carlos Salguero
 * @brief Declares the math class
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MATH_H
#define MATH_H

class Math
{
public:
    // Methods
    static float abs(float);
    static float floor(float);
    static float ceil(float);
    static float round(float);
    static float max(float, float);
    static float min(float, float);

    static float clamp(float, float, float);
    static float lerp(float, float, float);
    static float map(float, float, float, float, float);
    static float random(float, float);
    static float random(float);
    static float deegrees_to_radians(float);
    static float radians_to_deegrees(float);
    static float sin(float);
    static float cos(float);
    static float tan(float);
    static float asin(float);
    static float acos(float);
    static float atan(float);

private:
    // Constructor
    Math() = delete;
};

#endif //! MATH_H