/**
 * @file math.h
 * @author Carlos Salguero
 * @brief Declaration of math namespace functions
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

// C++ Standard Library
#include <cmath>

namespace Math
{
    // Simple functions
    /**
     * @brief
     * Adds two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Result of the addition
     */
    template <typename T>
    inline T add(T a, T b)
    {
        return a + b;
    }

    /**
     * @brief
     * Subtracts two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Result of the subtraction
     */
    template <typename T>
    inline T subtract(T a, T b)
    {
        return a - b;
    }

    /**
     * @brief
     * Multiplies two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Result of the multiplication
     */
    template <typename T>
    inline T multiply(T a, T b)
    {
        return a * b;
    }

    /**
     * @brief
     * Divides two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Result of the division
     */
    template <typename T>
    inline T divide(T a, T b)
    {
        if (b != 0)
            return a / b;

        else
            throw std::runtime_error("Error: Division by zero");
    }

    /**
     * @brief
     * Calculates the remainder of the division of two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Result of the remainder
     */
    template <typename T>
    inline T remainder(T a, T b)
    {
        return a % b;
    }

    /**
     * @brief
     * Calculates the power of a number with a non-negative integer exponent
     * @tparam T Type of the numbers
     * @param base Base
     * @param exponent Exponent
     * @return T Result of the power
     */
    template <typename T>
    inline T power(T base, unsigned int exponent)
    {
        T result = 1;

        for (unsigned int i = 0; i < exponent; i++)
            result *= base;

        return result;
    }

    /**
     * @brief
     * Calculates the square root of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the square root
     */
    template <typename T>
    inline T square_root(T a)
    {
        return std::sqrt(a);
    }

    // Mathematical constants
    /**
     * @brief
     * The mathematical constant PI
     */
    const double PI = 3.14159265358979323846;

    /**
     * @brief
     * The mathematical constant e (base of natural logarithm)
     */
    const double E = 2.71828182845904523536;

    // Trigonometric functions

    /**
     * @brief
     * Calculates the sine of an angle
     * @tparam T Type of the angle
     * @param angle Angle in radians
     * @return T Sine of the angle
     */
    template <typename T>
    inline T sine(T angle)
    {
        return std::sin(angle);
    }

    /**
     * @brief
     * Calculates the cosine of an angle
     * @tparam T Type of the angle
     * @param angle Angle in radians
     * @return T Cosine of the angle
     */
    template <typename T>
    inline T cosine(T angle)
    {
        return std::cos(angle);
    }

    /**
     * @brief
     * Calculates the tangent of an angle
     * @tparam T Type of the angle
     * @param angle Angle in radians
     * @return T Tangent of the angle
     */
    template <typename T>
    inline T tangent(T angle)
    {
        return std::tan(angle);
    }

    // Other functions
    /**
     * @brief
     * Calculates the absolute value of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Absolute value of the number
     */
    template <typename T>
    inline T absolute(T a)
    {
        return std::abs(a);
    }

    /**
     * @brief
     * Calculates the natural logarithm of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Natural logarithm of the number
     */
    template <typename T>
    inline T logarithm(T a)
    {
        if (a > 0)
            return std::log(a);

        else
            throw std::runtime_error("Error: Invalid argument for logarithm");
    }

    /**
     * @brief
     * Calculates the logarithm of a number in a given base
     * @tparam T Type of the number
     * @param a Number
     * @param base Base
     * @return T Logarithm of the number in the given base
     */
    template <typename T>
    inline T logarithm(T a, T base)
    {
        if (a > 0 && base > 0)
            return std::log(a) / std::log(base);

        else
            throw std::runtime_error("Error: Invalid argument for logarithm");
    }

    /**
     * @brief
     * Calculates the factorial of a non-negative integer
     * @tparam T Type of the number
     * @param a Number
     * @return T Factorial of the number
     */
    template <typename T>
    inline T factorial(T a)
    {
        if (a >= 0)
        {
            T result = 1;

            for (T i = 1; i <= a; i++)
                result *= i;

            return result;
        }

        else
            throw std::runtime_error("Error: Invalid argument for factorial");
    }

    /**
     * @brief
     * Calculates the greatest common divisor of two non-negative integers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Greatest common divisor of the numbers
     */
    template <typename T>
    inline T greatest_common_divisor(T a, T b)
    {
        if (a >= 0 && b >= 0)
        {
            while (b != 0)
            {
                T temp = b;
                b = a % b;
                a = temp;
            }

            return a;
        }

        else
            throw std::runtime_error("Error: Invalid argument for greatest common divisor");
    }

    /**
     * @brief
     * Calculates the least common multiple of two non-negative integers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Least common multiple of the numbers
     */
    template <typename T>
    inline T least_common_multiple(T a, T b)
    {
        if (a >= 0 && b >= 0)
            return a * b / greatest_common_divisor(a, b);

        else
            throw std::runtime_error("Error: Invalid argument for least common multiple");
    }

    /**
     * @brief
     * Calculates the greatest common divisor of two non-negative integers using the Euclidean algorithm
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Greatest common divisor of the numbers
     */
    template <typename T>
    inline T euclidean_greatest_common_divisor(T a, T b)
    {
        if (a >= 0 && b >= 0)
        {
            while (a != b)
            {
                if (a > b)
                    a -= b;

                else
                    b -= a;
            }

            return a;
        }

        else
            throw std::runtime_error("Error: Invalid argument for greatest common divisor");
    }

    /**
     * @brief
     * Calculates the least common multiple of two non-negative integers using the Euclidean algorithm
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Least common multiple of the numbers
     */
    template <typename T>
    inline T euclidean_least_common_multiple(T a, T b)
    {
        if (a >= 0 && b >= 0)
            return a * b / euclidean_greatest_common_divisor(a, b);

        else
            throw std::runtime_error("Error: Invalid argument for least common multiple");
    }

    /**
     * @brief
     * Calculates the remainder of the division of two integers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Remainder of the division of the numbers
     */
    template <typename T>
    inline T remainder(T a, T b)
    {
        if (b != 0)
            return a % b;

        else
            throw std::runtime_error("Error: Invalid argument for remainder");
    }

    /**
     * @brief
     * Calculates the quotient of the division of two integers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Quotient of the division of the numbers
     */
    template <typename T>
    inline T quotient(T a, T b)
    {
        if (b != 0)
            return a / b;

        else
            throw std::runtime_error("Error: Invalid argument for quotient");
    }

    /**
     * @brief
     * Calculates the square root of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Square root of the number
     */
    template <typename T>
    inline T square_root(T a)
    {
        if (a >= 0)
            return std::sqrt(a);

        else
            throw std::runtime_error("Error: Invalid argument for square root");
    }

    /**
     * @brief
     * Calculates the cube root of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Cube root of the number
     */
    template <typename T>
    inline T cube_root(T a)
    {
        return std::cbrt(a);
    }

    // Degree/radian conversion
    /**
     * @brief
     * Converts degrees to radians
     * @tparam T Type of the number
     * @param a Number in degrees
     * @return T Number in radians
     */
    template <typename T>
    inline T degrees_to_radians(T a)
    {
        return a * pi<T> / 180;
    }

    /**
     * @brief
     * Converts radians to degrees
     * @tparam T Type of the number
     * @param a Number in radians
     * @return T Number in degrees
     */
    template <typename T>
    inline T radians_to_degrees(T a)
    {
        return a * 180 / pi<T>;
    }

    // Interpolation
    /**
     * @brief
     * Linearly interpolates between two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @param t Interpolation factor
     * @return T Interpolated number
     */
    template <typename T>
    inline T lerp(T a, T b, T t)
    {
        return a + t * (b - a);
    }

    /**
     * @brief
     * Calculates the inverse of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Inverse of the number
     */
    template <typename T>
    inline T inverse(T a)
    {
        if (a != 0)
            return 1 / a;

        else
            throw std::runtime_error("Error: Invalid argument for inverse");
    }

    /**
     * @brief
     * Calculates the cubic interpolation of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Cubic interpolation of the number
     */
    template <typename T>
    inline T cubic_interpolation(T a)
    {
        return a * a * (3 - 2 * a);
    }
} // namespace math
