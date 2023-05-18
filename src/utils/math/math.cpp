/**
 * @file math.cpp
 * @author Carlos Salguero
 * @brief Implementation of the namespace Math
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "math.h"

namespace Math
{
    // Basic operations
    /**
     * @brief
     * Adds two values
     * @tparam T Type of the values
     * @param a First value
     * @param b Second value
     * @return T Result of the addition
     */
    template <typename T>
    T add(T a, T b) noexcept
    {
        return a + b;
    }

    /**
     * @brief
     * Squares a value
     * @tparam T Type of the value
     * @param a Value to square
     * @return T Result of the square
     */
    template <typename T>
    T square(T a) noexcept
    {
        return a * a;
    }

    /**
     * @brief
     * Square roots a value
     * @tparam T Type of the value
     * @param a Value to square root
     * @return T Result of the square root
     */
    template <typename T>
    T sqrt(T a) noexcept
    {
        // Newton's method
        T x = a;
        T y = 1.0f;

        while (x - y > episolon)
        {
            x = (x + y) / 2;
            y = a / x;
        }

        return x;
    }

    /**
     * @brief
     * Clamps a value between a minimum and a maximum
     * @tparam T Type of the value
     * @param value Value to clamp
     * @param min Minimum value
     * @param max Maximum value
     * @return T Clamped value
     */
    template <typename T>
    T clamp(T value, T min, T max) noexcept
    {
        if (value < min)
            return min;

        else if (value > max)
            return max;

        else
            return value;
    }

    /**
     * @brief
     * Linearly interpolates between two values
     * @tparam T Type of the values
     * @param a First value
     * @param b Second value
     * @param t Interpolation factor
     * @return T Interpolated value
     */
    template <typename T>
    T lerp(T a, T b, float t) noexcept
    {
        return a + (b - a) * t;
    }

    // Trigonometric functions
    /**
     * @brief
     * Converts degrees to radians
     * @tparam T Type of the value
     * @param degrees Value in degrees
     * @return T Value in radians
     */
    template <typename T>
    T to_radians(T degrees) noexcept
    {
        return degrees * pi / 180.0f;
    }

    /**
     * @brief
     * Converts radians to degrees
     * @tparam T Type of the value
     * @param radians Value in radians
     * @return T Value in degrees
     */
    template <typename T>
    T to_degrees(T radians) noexcept
    {
        return radians * 180.0f / pi;
    }

    /**
     * @brief
     * Calculates the sine of an angle
     * @tparam T Type of the value
     * @param angle Angle in radians
     * @return T Sine of the angle
     */
    template <typename T>
    T sin(T angle) noexcept
    {
        // Taylor series
        constexpr int num_terms = 10;

        T result = angle;
        T numerator = angle;
        T denominator = 1.0f;

        for (std::size_t i = 1; i < num_terms; ++i)
        {
            numerator *= angle * angle;
            denominator *= (2 * i) * (2 * i + 1);
            result += numerator / denominator * (i % 2 == 0 ? 1 : -1);
        }

        return result;
    }

    /**
     * @brief
     * Calculates the cosine of an angle
     * @tparam T Type of the value
     * @param angle Angle in radians
     * @return T Cosine of the angle
     */
    template <typename T>
    T cos(T angle) noexcept
    {
        // Taylor series
        constexpr int num_terms = 10;

        T result = 1.0f;
        T numerator = 1.0f;
        T denominator = 1.0f;

        for (std::size_t i = 1; i < num_terms; ++i)
        {
            numerator *= angle * angle;
            denominator *= (2 * i - 1) * (2 * i);
            result += numerator / denominator * (i % 2 == 0 ? 1 : -1);
        }

        return result;
    }

    /**
     * @brief
     * Calculates the tangent of an angle
     * @tparam T Type of the value
     * @param angle Angle in radians
     * @return T Tangent of the angle
     */
    template <typename T>
    T tan(T angle) noexcept
    {
        return sin(angle) / cos(angle);
    }

    /**
     * @brief
     * Calculates the arc sine of an angle
     * @tparam T Type of the value
     * @param angle Angle in radians
     * @return T Arc sine of the angle
     */
    template <typename T>
    T asin(T angle) noexcept
    {
        // Taylor series
        constexpr int num_terms = 10;

        T result = angle;
        T numerator = angle;
        T denominator = 1.0f;

        for (std::size_t i = 1; i < num_terms; ++i)
        {
            numerator *= angle * angle * (2 * i - 1) * (2 * i - 1);
            denominator *= (2 * i) * (2 * i + 1);
            result += numerator / denominator * (i % 2 == 0 ? 1 : -1);
        }

        return result;
    }

    /**
     * @brief
     * Calculates the arc cosine of an angle
     * @tparam T Type of the value
     * @param angle Angle in radians
     * @return T Arc cosine of the angle
     */
    template <typename T>
    T acos(T angle) noexcept
    {
        return pi / 2.0f - asin(angle);
    }

    /**
     * @brief
     * Calculates the arc tangent of an angle
     * @tparam T Type of the value
     * @param angle Angle in radians
     * @return T Arc tangent of the angle
     */
    template <typename T>
    T atan(T angle) noexcept
    {
        // Taylor series
        constexpr int num_terms = 10;

        T result = angle;
        T numerator = angle;
        T denominator = 1.0f;

        for (std::size_t i = 1; i < num_terms; ++i)
        {
            numerator *= angle * angle;
            denominator = 2 * i + 1;
            result += numerator / denominator * (i % 2 == 0 ? 1 : -1);
        }

        return result;
    }

    /**
     * @brief
     * Calculates the arc tangent of two values
     * @tparam T Type of the values
     * @param y Y value
     * @param x X value
     * @return T Arc tangent of the values
     */
    template <typename T>
    T atan2(T y, T x) noexcept
    {
        return atan(y / x);
    }

    // Vector operations
    /**
     * @brief
     * Adds two vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3 Result of the addition
     */
    Vector3 add(const Vector3 &a, const Vector3 &b) noexcept
    {
        return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    /**
     * @brief
     * Subtracts two vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3 Result of the subtraction
     */
    Vector3 subtract(const Vector3 &a, const Vector3 &b) noexcept
    {
        return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    /**
     * @brief
     * Multiplies two vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3 Result of the multiplication
     */
    Vector3 multiply(const Vector3 &a, const Vector3 &b) noexcept
    {
        return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    /**
     * @brief
     * Divides two vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3 Result of the division
     */
    Vector3 divide(const Vector3 &a, const Vector3 &b) noexcept
    {
        return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    /**
     * @brief
     * Normalizes a vector
     * @param vector Vector to normalize
     * @return Vector3 Normalized vector
     */
    Vector3 normalize(const Vector3 &vector) noexcept
    {
        float length =
            sqrt(vector.x * vector.x + vector.y * vector.y +
                 vector.z * vector.z);

        return Vector3(vector.x / length, vector.y / length, vector.z / length);
    }

    /**
     * @brief
     * Cross product of two vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3 Cross product of the vectors
     */
    Vector3 cross(const Vector3 &a, const Vector3 &b) noexcept
    {
        return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                       a.x * b.y - a.y * b.x);
    }

    /**
     * @brief
     * Interpolates between two vectors
     * @param a First vector
     * @param b Second vector
     * @param t Interpolation value
     * @return Vector3 Interpolated vector
     */
    Vector3 lerp(const Vector3 &a, const Vector3 &b, float t) noexcept
    {
        return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t,
                       a.z + (b.z - a.z) * t);
    }

    /**
     * @brief
     * Calculates the dot product of two vectors
     * @param a First vector
     * @param b Second vector
     * @return float Dot product of the vectors
     */
    float dot(const Vector3 &a, const Vector3 &b) noexcept
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /**
     * @brief
     * Calculates the length of a vector
     * @param vector Vector to calculate the length of
     * @return float Length of the vector
     */
    float length(const Vector3 &vector) noexcept
    {
        return sqrt(vector.x * vector.x + vector.y * vector.y +
                    vector.z * vector.z);
    }

    // Matrix operations
    /**
     * @brief
     * Multiplies two matrices
     * @param a First matrix
     * @param b Second matrix
     * @return Matrix4 Result of the multiplication
     */
    Matrix4 multiply(const Matrix4 &a, const Matrix4 &b) noexcept
    {
        Matrix4 result;

        return result;
    }
}