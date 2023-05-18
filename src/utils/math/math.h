/**
 * @file math.h
 * @author Carlos Salguero
 * @brief Declares the namespace class
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MATH_H
#define MATH_H

namespace Math
{
    // Constants
    constexpr float pi = 3.14159265358979323846f;
    constexpr float episolon = 0.0001f;

    // Functions
    // Basic operations
    template <typename T>
    T add(T a, T b) noexcept;

    template <typename T>
    T square(T a) noexcept;

    template <typename T>
    T sqrt(T a) noexcept;

    template <typename T>
    T clamp(T value, T min, T max) noexcept;

    template <typename T>
    T lerp(T a, T b, float t) noexcept;

    // Trigonometric functions
    template <typename T>
    T to_radians(T degrees) noexcept;

    template <typename T>
    T to_degrees(T radians) noexcept;

    template <typename T>
    T sin(T angle) noexcept;

    template <typename T>
    T cos(T angle) noexcept;

    template <typename T>
    T tan(T angle) noexcept;

    template <typename T>
    T asin(T angle) noexcept;

    template <typename T>
    T acos(T angle) noexcept;

    template <typename T>
    T atan(T angle) noexcept;

    template <typename T>
    T atan2(T y, T x) noexcept;

    // Vector operations
    struct Vector3
    {
        float x, y, z;
    };

    Vector3 add(const Vector3 &a, const Vector3 &b) noexcept;
    Vector3 subtract(const Vector3 &a, const Vector3 &b) noexcept;
    Vector3 multiply(const Vector3 &a, const Vector3 &b) noexcept;
    Vector3 divide(const Vector3 &a, const Vector3 &b) noexcept;
    Vector3 normalize(const Vector3 &a) noexcept;
    Vector3 cross(const Vector3 &a, const Vector3 &b) noexcept;
    Vector3 lerp(const Vector3 &a, const Vector3 &b, float t) noexcept;
    float dot(const Vector3 &a, const Vector3 &b) noexcept;
    float length(const Vector3 &a) noexcept;

    // Matrix operations
    struct Matrix4
    {
        float elements[4 * 4];
    };

    Matrix4 multiply(const Matrix4 &a, const Matrix4 &b) noexcept;
    Matrix4 identity() noexcept;
    Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far) noexcept;
    Matrix4 perspective(float fov, float aspect_ratio, float near, float far) noexcept;
    Matrix4 translate(const Matrix4 &a, const Vector3 &b) noexcept;
    Matrix4 rotate(const Matrix4 &a, const Vector3 &b) noexcept;
    Matrix4 scale(const Matrix4 &a, const Vector3 &b) noexcept;
    Matrix4 inverse(const Matrix4 &a) noexcept;
}

#endif //! MATH_H