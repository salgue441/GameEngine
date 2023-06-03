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

#ifndef MATH_H
#define MATH_H

// C++ Standard Library
#include <cstdint>

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
     * Substracts two numbers
     * @tparam T Type of the numbers
     * @param a First number
     * @param b Second number
     * @return T Result of the substraction
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
        return a / b;
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
     * Calculates the power of a number
     * @tparam T Type of the numbers
     * @param a Base
     * @param b Exponent
     * @return T Result of the power
     */
    template <typename T>
    inline T power(T a, T b)
    {
        T result = 1;

        for (T i = 0; i < b; i++)
            result *= a;

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
        T result = 0;

        while (result * result < a)
            result++;

        return result;
    }

    /**
     * @brief
     * Calculates the factorial of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the factorial
     */
    template <typename T>
    inline T factorial(T a)
    {
        T result = 1;

        for (T i = 1; i <= a; i++)
            result *= i;

        return result;
    }

    /**
     * @brief
     * Calculates the absolute value of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the absolute value
     */
    template <typename T>
    inline T absolute(T a)
    {
        return a < 0 ? -a : a;
    }

    /**
     * @brief
     * Calculates the logarithm of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the logarithm
     */
    template <typename T>
    inline T logarithm(T a)
    {
        T result = 0;

        while (a > 1)
        {
            a /= 10;
            result++;
        }

        return result;
    }

    /**
     * @brief
     * Calculates the natural logarithm of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the natural logarithm
     */
    template <typename T>
    inline T natural_logarithm(T a)
    {
        T result = 0;

        while (a > 1)
        {
            a /= 10;
            result++;
        }

        return result;
    }

    /**
     * @brief
     * Calculates the sine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the sine
     */
    template <typename T>
    inline T sine(T a)
    {
        auto result = 0;

        for (T i = 0; i < 10; i++)
            result += power(-1, i) * power(a, 2 * i + 1) / factorial(2 * i + 1);

        return result;
    }

    /**
     * @brief
     * Calculates the cosine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the cosine
     */
    template <typename T>
    inline T cosine(T a)
    {
        auto result = 0;

        for (T i = 0; i < 10; i++)
            result += power(-1, i) * power(a, 2 * i) / factorial(2 * i);

        return result;
    }

    /**
     * @brief
     * Calculates the tangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the tangent
     */
    template <typename T>
    inline T tangent(T a)
    {
        return sine(a) / cosine(a);
    }

    /**
     * @brief
     * Calculates the cotangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the cotangent
     */
    template <typename T>
    inline T cotangent(T a)
    {
        return cosine(a) / sine(a);
    }

    /**
     * @brief
     * Calculates the secant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the secant
     */
    template <typename T>
    inline T secant(T a)
    {
        return 1 / cosine(a);
    }

    /**
     * @brief
     * Calculates the cosecant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the cosecant
     */
    template <typename T>
    inline T cosecant(T a)
    {
        return 1 / sine(a);
    }

    /**
     * @brief
     * Calculates the hyperbolic sine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic sine
     */
    template <typename T>
    inline T hyperbolic_sine(T a)
    {
        return (power(e, a) - power(e, -a)) / 2;
    }

    /**
     * @brief
     * Calculates the hyperbolic cosine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic cosine
     */
    template <typename T>
    inline T hyperbolic_cosine(T a)
    {
        return (power(e, a) + power(e, -a)) / 2;
    }

    /**
     * @brief
     * Calculates the hyperbolic tangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic tangent
     */
    template <typename T>
    inline T hyperbolic_tangent(T a)
    {
        return hyperbolic_sine(a) / hyperbolic_cosine(a);
    }

    /**
     * @brief
     * Calculates the hyperbolic cotangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic cotangent
     */
    template <typename T>
    inline T hyperbolic_cotangent(T a)
    {
        return hyperbolic_cosine(a) / hyperbolic_sine(a);
    }

    /**
     * @brief
     * Calculates the hyperbolic secant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic secant
     */
    template <typename T>
    inline T hyperbolic_secant(T a)
    {
        return 1 / hyperbolic_cosine(a);
    }

    /**
     * @brief
     * Calculates the hyperbolic cosecant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic cosecant
     */
    template <typename T>
    inline T hyperbolic_cosecant(T a)
    {
        return 1 / hyperbolic_sine(a);
    }

    /**
     * @brief
     * Calculates the arc sine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the arc sine
     */
    template <typename T>
    inline T arc_sine(T a)
    {
        auto result = 0;

        for (T i = 0; i < 10; i++)
            result += factorial(2 * i) * power(a, 2 * i + 1) /
                      (power(4, i) * power(factorial(i), 2) * (2 * i + 1));

        return result;
    }

    /**
     * @brief
     * Calculates the arc cosine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the arc cosine
     */
    template <typename T>
    inline T arc_cosine(T a)
    {
        return pi / 2 - arc_sine(a);
    }

    /**
     * @brief
     * Calculates the arc tangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the arc tangent
     */
    template <typename T>
    inline T arc_tangent(T a)
    {
        auto result = 0;

        for (T i = 0; i < 10; i++)
            result += power(-1, i) * power(a, 2 * i + 1) / (2 * i + 1);

        return result;
    }

    /**
     * @brief
     * Calculates the arc cotangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the arc cotangent
     */
    template <typename T>
    inline T arc_cotangent(T a)
    {
        return pi / 2 - arc_tangent(a);
    }

    /**
     * @brief
     * Calculates the arc secant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the arc secant
     */
    template <typename T>
    inline T arc_secant(T a)
    {
        return arc_cosine(1 / a);
    }

    /**
     * @brief
     * Calculates the arc cosecant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the arc cosecant
     */
    template <typename T>
    inline T arc_cosecant(T a)
    {
        return arc_sine(1 / a);
    }

    /**
     * @brief
     * Calculates the hyperbolic arc sine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic arc sine
     */
    template <typename T>
    inline T hyperbolic_arc_sine(T a)
    {
        return ln(a + sqrt(power(a, 2) + 1));
    }

    /**
     * @brief
     * Calculates the hyperbolic arc cosine of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic arc cosine
     */
    template <typename T>
    inline T hyperbolic_arc_cosine(T a)
    {
        return ln(a + sqrt(power(a, 2) - 1));
    }

    /**
     * @brief
     * Calculates the hyperbolic arc tangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic arc tangent
     */
    template <typename T>
    inline T hyperbolic_arc_tangent(T a)
    {
        return ln((1 + a) / (1 - a)) / 2;
    }

    /**
     * @brief
     * Calculates the hyperbolic arc cotangent of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic arc cotangent
     */
    template <typename T>
    inline T hyperbolic_arc_cotangent(T a)
    {
        return ln((a + 1) / (a - 1)) / 2;
    }

    /**
     * @brief
     * Calculates the hyperbolic arc secant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic arc secant
     */
    template <typename T>
    inline T hyperbolic_arc_secant(T a)
    {
        return ln((sqrt(-power(a, 2) + 1) + 1) / a);
    }

    /**
     * @brief
     * Calculates the hyperbolic arc cosecant of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the hyperbolic arc cosecant
     */
    template <typename T>
    inline T hyperbolic_arc_cosecant(T a)
    {
        return ln((sqrt(power(a, 2) + 1) + 1) / a);
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
        return power(a, 0.5);
    }

    /**
     * @brief
     * Calculates the cubic root of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the cubic root
     */
    template <typename T>
    inline T cubic_root(T a)
    {
        return power(a, 1.0 / 3.0);
    }

    /**
     * @brief
     * Calculates the n-th root of a number
     * @tparam T Type of the number
     * @param a Number
     * @param n Root
     * @return T Result of the n-th root
     */
    template <typename T>
    inline T n_root(T a, T n)
    {
        return power(a, 1.0 / n);
    }

    /**
     * @brief
     * Calculates the logarithm of a number
     * @tparam T Type of the number
     * @param a Number
     * @param base Base
     * @return T Result of the logarithm
     */
    template <typename T>
    inline T logarithm(T a, T base)
    {
        return ln(a) / ln(base);
    }

    /**
     * @brief
     * Calculates the natural logarithm of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the natural logarithm
     */
    template <typename T>
    inline T ln(T a)
    {
        return logarithm(a, e);
    }

    /**
     * @brief
     * Calculates the logarithm base 10 of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the logarithm base 10
     */
    template <typename T>
    inline T log10(T a)
    {
        return logarithm(a, 10);
    }

    /**
     * @brief
     * Calculates the logarithm base 2 of a number
     * @tparam T Type of the number
     * @param a Number
     * @return T Result of the logarithm base 2
     */
    template <typename T>
    inline T log2(T a)
    {
        return logarithm(a, 2);
    }

    // Vectors
    template <typename T>
    struct Vector3
    {
        T x, y, z;
    };

    // Vector operations
    /**
     * @brief
     * Adds two vectors
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the addition
     */
    template <typename T>
    inline Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b)
    {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    /**
     * @brief
     * Subtracts two vectors
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the subtraction
     */
    template <typename T>
    inline Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b)
    {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    /**
     * @brief
     * Multiplies two vectors
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the multiplication
     */
    template <typename T>
    inline Vector3<T> operator*(const Vector3<T> &a, const Vector3<T> &b)
    {
        return {a.x * b.x, a.y * b.y, a.z * b.z};
    }

    /**
     * @brief
     * Divides two vectors
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the division
     */
    template <typename T>
    inline Vector3<T> operator/(const Vector3<T> &a, const Vector3<T> &b)
    {
        return {a.x / b.x, a.y / b.y, a.z / b.z};
    }

    /**
     * @brief
     * Adds a vector to another
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the addition
     */
    template <typename T>
    inline Vector3<T> &operator+=(Vector3<T> &a, const Vector3<T> &b)
    {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
        return a;
    }

    /**
     * @brief
     * Subtracts a vector to another
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the subtraction
     */
    template <typename T>
    inline Vector3<T> &operator-=(Vector3<T> &a, const Vector3<T> &b)
    {
        a.x -= b.x;
        a.y -= b.y;
        a.z -= b.z;
        return a;
    }

    /**
     * @brief
     * Multiplies a vector to another
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the multiplication
     */
    template <typename T>
    inline Vector3<T> &operator*=(Vector3<T> &a, const Vector3<T> &b)
    {
        a.x *= b.x;
        a.y *= b.y;
        a.z *= b.z;
        return a;
    }

    /**
     * @brief
     * Divides a vector to another
     * @tparam T Type of the vectors
     * @param a First vector
     * @param b Second vector
     * @return Vector3<T> Result of the division
     */
    template <typename T>
    inline Vector3<T> &operator/=(Vector3<T> &a, const Vector3<T> &b)
    {
        a.x /= b.x;
        a.y /= b.y;
        a.z /= b.z;
        return a;
    }

    /**
     * @brief
     * Adds a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the addition
     */
    template <typename T>
    inline Vector3<T> operator+(const Vector3<T> &a, const T &b)
    {
        return {a.x + b, a.y + b, a.z + b};
    }

    /**
     * @brief
     * Subtracts a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the subtraction
     */
    template <typename T>
    inline Vector3<T> operator-(const Vector3<T> &a, const T &b)
    {
        return {a.x - b, a.y - b, a.z - b};
    }

    /**
     * @brief
     * Multiplies a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the multiplication
     */
    template <typename T>
    inline Vector3<T> operator*(const Vector3<T> &a, const T &b)
    {
        return {a.x * b, a.y * b, a.z * b};
    }

    /**
     * @brief
     * Divides a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the division
     */
    template <typename T>
    inline Vector3<T> operator/(const Vector3<T> &a, const T &b)
    {
        return {a.x / b, a.y / b, a.z / b};
    }

    /**
     * @brief
     * Adds a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the addition
     */
    template <typename T>
    inline Vector3<T> &operator+=(Vector3<T> &a, const T &b)
    {
        a.x += b;
        a.y += b;
        a.z += b;
        return a;
    }

    /**
     * @brief
     * Subtracts a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the subtraction
     */
    template <typename T>
    inline Vector3<T> &operator-=(Vector3<T> &a, const T &b)
    {
        a.x -= b;
        a.y -= b;
        a.z -= b;
        return a;
    }

    /**
     * @brief
     * Multiplies a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the multiplication
     */
    template <typename T>
    inline Vector3<T> &operator*=(Vector3<T> &a, const T &b)
    {
        a.x *= b;
        a.y *= b;
        a.z *= b;
        return a;
    }

    /**
     * @brief
     * Divides a scalar to a vector
     * @tparam T Type of the vector
     * @param a Vector
     * @param b Scalar
     * @return Vector3<T> Result of the division
     */
    template <typename T>
    inline Vector3<T> &operator/=(Vector3<T> &a, const T &b)
    {
        a.x /= b;
        a.y /= b;
        a.z /= b;
        return a;
    }

} // namespace Math

#endif //! MATH_H