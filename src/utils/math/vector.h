/**
 * @file vector.h
 * @author Carlos Salguero
 * @brief Custom vector class for the game engine
 * @version 0.1
 * @date 2023-06-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

// C++ Standard Library
#include <vector>
#include <stdexcept>
#include <cassert>

// Project files
#include "math.h"

// Class
/**
 * @class Vector
 * @brief Custom vector class for the game engine
 */
namespace Math
{
    template <class T>
    class Vector
    {
    public:
        // Constructors
        Vector() = default;
        Vector(std::initializer_list<T> init) : m_elements(init) {}
        Vector(std::size_t size) : m_elements(size) {}
        Vector(const Vector<T> &other) : m_elements(other.m_elements) {}
        Vector(Vector<T> &&other) : m_elements(std::move(other.m_elements)) {}

        // Operators
        /**
         * @brief
         * Overloads the [] operator to access the elements of the vector
         * @param index The index of the element to access
         * @return T& The element at the given index
         */
        T &operator[](std::size_t index)
        {
            assert(index < m_elements.size() && "Index out of bounds");
            return m_elements[index];
        }

        /**
         * @brief
         * Overloads the [] operator to access the elements of the vector
         * @param index The index of the element to access
         * @return T& The element at the given index
         */
        const T &operator[](std::size_t index) const
        {
            assert(index < m_elements.size() && "Index out of bounds");
            return m_elements[index];
        }

        /**
         * @brief
         * Overloads the = operator to assign a vector to another vector
         * @param other The vector to assign to this vector
         * @return Vector<T>& The vector assigned to this vector
         */
        Vector<T> &operator=(const Vector<T> &other)
        {
            if (this != &other)
                m_elements = other.m_elements;

            return *this;
        }

        /**
         * @brief
         * Overloads the = operator to assign a vector to another vector
         * @param other The vector to assign to this vector
         * @return Vector<T>& The vector assigned to this vector
         */
        Vector<T> &operator=(Vector<T> &&other)
        {
            if (this != &other)
                m_elements = std::move(other.m_elements);

            return *this;
        }

        /**
         * @brief
         * Overloads the comparison operator to compare two vectors
         * @param other The vector to compare to this vector
         * @return true If the vectors are equal
         * @return false If the vectors are not equal
         */
        bool operator==(const Vector<T> &other) const
        {
            if (m_elements.size() != other.m_elements.size())
                return false;

            return m_elements == other.m_elements;
        }

        /**
         * @brief
         * Overloads the comparison operator to compare two vectors
         * @param other The vector to compare to this vector
         * @return true If the vectors are not equal
         * @return false If the vectors are equal
         */
        bool operator!=(const Vector<T> &other) const
        {
            return m_elements != other.m_elements;
        }

        /**
         * @brief
         * Overloads the + operator to add two vectors
         * @param other The vector to add to this vector
         * @return Vector<T> The sum of the two vectors
         */
        Vector<T> operator+(const Vector<T> &other) const
        {
            assert(m_elements.size() == other.m_elements.size() &&
                   "Vectors must be the same size to add them");

            Vector<T> result(size());

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result[i] = m_elements[i] + other[i];

            return result;
        }

        /**
         * @brief
         * Overloads the - operator to subtract two vectors
         * @param other The vector to subtract from this vector
         * @return Vector<T> The difference of the two vectors
         */
        Vector<T> operator-(const Vector<T> &other) const
        {
            assert(m_elements.size() == other.m_elements.size() &&
                   "Vectors must be the same size to subtract them");

            Vector<T> result(size());

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result[i] = m_elements[i] - other[i];

            return result;
        }

        /**
         * @brief
         * Overloads the * operator to multiply two vectors
         * @param other The vector to multiply with this vector
         * @return Vector<T> The product of the two vectors
         */
        Vector<T> operator*(const Vector<T> &other) const
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to multiply them");

            Vector<T> result(size());

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result.m_elements.push_back(
                    m_elements[i] * other.m_elements[i]);

            return result;
        }

        /**
         * @brief
         * Overloads the / operator to divide two vectors
         * @param other The vector to divide this vector by
         * @return Vector<T> The quotient of the two vectors
         */
        Vector<T> operator/(const Vector<T> &other) const
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to divide them");

            Vector<T> result;

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result.m_elements.push_back(
                    m_elements[i] / other.m_elements[i]);

            return result;
        }

        /**
         * @brief
         * Overloads the += operator to add two vectors
         * @param other The vector to add to this vector
         * @return Vector<T>& The sum of the two vectors
         */
        Vector<T> &operator+=(const Vector<T> &other)
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to add them");

            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] += other.m_elements[i];

            return *this;
        }

        /**
         * @brief
         * Overloads the -= operator to subtract two vectors
         * @param other The vector to subtract from this vector
         * @return Vector<T>& The difference of the two vectors
         */
        Vector<T> &operator-=(const Vector<T> &other)
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to subtract them");

            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] -= other.m_elements[i];

            return *this;
        }

        /**
         * @brief
         * Overloads the *= operator to multiply two vectors
         * @param other The vector to multiply with this vector
         * @return Vector<T>& The product of the two vectors
         */
        Vector<T> &operator*=(const Vector<T> &other)
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to multiply them");

            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] *= other.m_elements[i];

            return *this;
        }

        /**
         * @brief
         * Overloads the /= operator to divide two vectors
         * @param other The vector to divide this vector by
         * @return Vector<T>& The quotient of the two vectors
         */
        Vector<T> &operator/=(const Vector<T> &other)
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to divide them");

            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] /= other.m_elements[i];

            return *this;
        }

        /**
         * @brief
         * Overloads the + operator to add a scalar to a vector
         * @param scalar The scalar to add to the vector
         * @return Vector<T> The sum of the vector and the scalar
         */
        Vector<T> operator+(const T &scalar) const
        {
            Vector<T> result;

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result.m_elements.push_back(m_elements[i] + scalar);

            return result;
        }

        /**
         * @brief
         * Overloads the - operator to subtract a scalar from a vector
         * @param scalar The scalar to subtract from the vector
         * @return Vector<T> The difference of the vector and the scalar
         */
        Vector<T> operator-(const T &scalar) const
        {
            Vector<T> result;

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result.m_elements.push_back(m_elements[i] - scalar);

            return result;
        }

        /**
         * @brief
         * Overloads the * operator to multiply a scalar with a vector
         * @param scalar The scalar to multiply with the vector
         * @return Vector<T> The product of the vector and the scalar
         */
        Vector<T> operator*(const T &scalar) const
        {
            Vector<T> result(size());

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result[i] = m_elements[i] * scalar;

            return result;
        }

        /**
         * @brief
         * Overloads the / operator to divide a vector by a scalar
         * @param scalar The scalar to divide the vector by
         * @return Vector<T> The quotient of the vector and the scalar
         */
        Vector<T> operator/(const T &scalar) const
        {
            assert(scalar != 0 && "Cannot divide by zero");
            Vector<T> result(size());

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result[i] = m_elements[i] / scalar;

            return result;
        }

        /**
         * @brief
         * Overloads the += operator to add a scalar to a vector
         * @param scalar The scalar to add to the vector
         * @return Vector<T>& The sum of the vector and the scalar
         */
        Vector<T> &operator+=(const T &scalar)
        {
            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] += scalar;

            return *this;
        }

        /**
         * @brief
         * Overloads the -= operator to subtract a scalar from a vector
         * @param scalar The scalar to subtract from the vector
         * @return Vector<T>& The difference of the vector and the scalar
         */
        Vector<T> &operator-=(const T &scalar)
        {
            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] -= scalar;

            return *this;
        }

        /**
         * @brief
         * Overloads the *= operator to multiply a scalar with a vector
         * @param scalar The scalar to multiply with the vector
         * @return Vector<T>& The product of the vector and the scalar
         */
        Vector<T> &operator*=(const T &scalar)
        {
            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] *= scalar;

            return *this;
        }

        /**
         * @brief
         * Overloads the /= operator to divide a vector by a scalar
         * @param scalar The scalar to divide the vector by
         * @return Vector<T>& The quotient of the vector and the scalar
         */
        Vector<T> &operator/=(const T &scalar)
        {
            assert(scalar != 0 && "Cannot divide by zero");

            for (std::size_t i = 0; i < m_elements.size(); i++)
                m_elements[i] /= scalar;

            return *this;
        }

        // Methods
        /**
         * @brief
         * Returns the size of the vector
         * @return std::size_t The size of the vector
         */
        std::size_t size() const
        {
            return m_elements.size();
        }

        /**
         * @brief
         * Returns the magnitude of the vector
         * @return T The magnitude of the vector
         */
        T magnitude() const
        {
            T sum = 0;

            for (std::size_t i = 0; i < m_elements.size(); i++)
                sum += m_elements[i] * m_elements[i];

            return square_root(sum);
        }

        /**
         * @brief
         * Returns the unit vector of the vector
         * @return Vector<T> The unit vector of the vector
         */
        Vector<T> unit_vector() const
        {
            assert(magnitude() != 0 && "Cannot divide by zero");

            return *this / magnitude();
        }

        /**
         * @brief
         * Returns the squared magnitude of the vector
         * @return T The squared magnitude of the vector
         */
        T squared_magnitude() const
        {
            T sum = 0;

            for (std::size_t i = 0; i < m_elements.size(); i++)
                sum += m_elements[i] * m_elements[i];

            return sum;
        }

        /**
         * @brief
         * Returns the dot product of two vectors
         * @param other The vector to dot with this vector
         * @return T The dot product of the two vectors
         */
        T dot(const Vector<T> &other) const
        {
            assert(m_elements.size() == other.m_elements.size() &&
                   "Vectors must be the same size to dot them");

            T sum = 0;

            for (std::size_t i = 0; i < m_elements.size(); i++)
                sum += m_elements[i] * other.m_elements[i];

            return sum;
        }

        /**
         * @brief
         * Returns the cross product of two vectors
         * @param other The vector to cross with this vector
         * @return Vector<T> The cross product of the two vectors
         */
        Vector<T> cross(const Vector<T> &other) const
        {
            assert(m_elements.size() == 3 && other.m_elements.size() == 3 &&
                   "Vectors must be 3D to cross them");

            Vector<T> result(3);

            result[0] = m_elements[1] * other[2] - m_elements[2] * other[1];
            result[1] = m_elements[2] * other[0] - m_elements[0] * other[2];
            result[2] = m_elements[0] * other[1] - m_elements[1] * other[0];

            return result;
        }

        /**
         * @brief
         * Returns the normalized vector
         * @return Vector<T> The normalized vector
         */
        Vector<T> normalize() const
        {
            T mag = magnitude();
            assert(mag != 0 && "Cannot normalize a zero vector");

            Vector<T> result(size());

            for (std::size_t i = 0; i < m_elements.size(); i++)
                result[i] = m_elements[i] / mag;

            return result;
        }

        /**
         * @brief
         * Returns the angle between two vectors
         * @param other The vector to find the angle between
         * @return T The angle between the two vectors
         */
        T angle(const Vector<T> &other) const
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to find the angle between "
                    "them");

            return arc_cosine(dot(other) / (magnitude() * other.magnitude()));
        }

        /**
         * @brief
         * Linearly interpolates between two vectors
         * @param other The vector to interpolate with
         * @param t The interpolation factor
         * @return Vector<T> The interpolated vector
         */
        Vector<T> lerp(const Vector<T> &other, const T &t) const
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to interpolate between "
                    "them");

            return *this + (other - *this) * t;
        }

        /**
         * @brief
         * Returns the cubic interpolation between two vectors
         * @param other The vector to interpolate with
         * @param t The interpolation factor
         * @return Vector<T> The interpolated vector
         */
        Vector<T> cubic_interpolation(const Vector<T> &other, const T &t) const
        {
            if (m_elements.size() != other.m_elements.size())
                throw std::invalid_argument(
                    "Vectors must be the same size to interpolate between "
                    "them");

            T t2 = t * t;
            T t3 = t2 * t;

            return *this * (2 * t3 - 3 * t2 + 1) +
                   other * (3 * t2 - 2 * t3) +
                   (*this - other) * (t3 - 2 * t2 + t);
        }

    private:
        std::vector<T> m_elements;
    };
}