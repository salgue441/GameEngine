/**
 * @file matrix.h
 * @author Carlos Salguero
 * @brief Implementation of a matrix class for the game engine
 * @version 0.1
 * @date 2023-06-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

// C++ Standard Library
#include <unordered_map>
#include <utility>
#include <stdexcept>

namespace Math
{
    template <class T>
    class Matrix
    {
    public:
        // Constructors
        Matrix() = default;
        Matrix(std::size_t rows, std::size_t cols)
            : m_rows(rows), m_cols(cols) {}
        Matrix(const Matrix &other)
            : m_rows(other.m_rows), m_cols(other.m_cols),
              m_elements(other.m_elements) {}
        Matrix(Matrix &&other) noexcept
            : m_rows(std::move(other.m_rows)),
              m_cols(std::move(other.m_cols)),
              m_elements(std::move(other.m_elements)) {}

        // Operators
        /**
         * @brief Accesses the element at the specified position.
         * @param row The row of the element.
         * @param col The column of the element.
         * @return T& The element at the specified position.
         * @throws std::out_of_range If the position is out of bounds.
         */
        T &operator()(std::size_t row, std::size_t col)
        {
            if (row >= m_rows || col >= m_cols)
                throw std::out_of_range("Matrix subscript out of range");

            return m_elements[std::make_pair(row, col)];
        }

        /**
         * @brief Accesses the element at the specified position.
         * @param row The row of the element.
         * @param col The column of the element.
         * @return const T& The element at the specified position.
         * @throws std::out_of_range If the position is out of bounds.
         */
        const T &operator()(std::size_t row, std::size_t col) const
        {
            if (row >= m_rows || col >= m_cols)
                throw std::out_of_range("Matrix subscript out of range");

            return m_elements.at(std::make_pair(row, col));
        }

        /**
         * @brief Accesses the element at the specified position.
         * @param row The row of the element.
         * @param col The column of the element.
         * @return T& The element at the specified position.
         * @throws std::out_of_range If the position is out of bounds.
         */
        T &operator()(std::size_t row, std::size_t col) const
        {
            if (row >= m_rows || col >= m_cols)
                throw std::out_of_range("Matrix subscript out of range");

            return m_elements.at(std::make_pair(row, col));
        }

        /**
         * @brief Assigns the contents of another matrix to this matrix.
         * @param other The matrix to assign.
         * @return Matrix<T>& The assigned matrix.
         */
        Matrix<T> &operator=(const Matrix<T> &other)
        {
            m_rows = other.m_rows;
            m_cols = other.m_cols;
            m_elements = other.m_elements;

            return *this;
        }

        /**
         * @brief Assigns the contents of another matrix to this matrix.
         * @param other The matrix to assign.
         * @return Matrix<T>& The assigned matrix.
         */
        Matrix<T> &operator=(Matrix<T> &&other) noexcept
        {
            m_rows = std::move(other.m_rows);
            m_cols = std::move(other.m_cols);
            m_elements = std::move(other.m_elements);

            return *this;
        }

        /**
         * @brief Multiplies this matrix by a scalar value.
         * @param scalar The scalar value to multiply by.
         * @return Matrix<T>& Reference to this matrix after multiplication.
         */
        Matrix<T> &operator*=(const T &scalar)
        {
            for (auto &element : m_elements)
                element.second *= scalar;

            return *this;
        }

        /**
         * @brief Divides this matrix by a scalar value.
         * @param scalar The scalar value to divide by.
         * @return Matrix<T>& Reference to this matrix after division.
         * @throws std::invalid_argument If the scalar value is zero.
         */
        Matrix<T> &operator/=(const T &scalar)
        {
            if (scalar == 0)
                throw std::invalid_argument("Matrix division by zero");

            for (auto &element : m_elements)
                element.second /= scalar;

            return *this;
        }

        /**
         * @brief Adds another matrix to this matrix.
         * @param other The matrix to add.
         * @return Matrix<T>& Reference to this matrix after addition.
         * @throws std::invalid_argument If the matrices are not the same size.
         */
        Matrix<T> &operator+=(const Matrix<T> &other)
        {
            if (m_rows != other.m_rows || m_cols != other.m_cols)
                throw std::invalid_argument("Matrix addition of different sizes");

            for (auto &element : other.m_elements)
                m_elements[element.first] += element.second;

            return *this;
        }

        /**
         * @brief Subtracts another matrix from this matrix.
         * @param other The matrix to subtract.
         * @return Matrix<T>& Reference to this matrix after subtraction.
         * @throws std::invalid_argument If the matrices are not the same size.
         */
        Matrix<T> &operator-=(const Matrix<T> &other)
        {
            if (m_rows != other.m_rows || m_cols != other.m_cols)
                throw std::invalid_argument("Matrix subtraction of different sizes");

            for (auto &element : other.m_elements)
                m_elements[element.first] -= element.second;

            return *this;
        }

        /**
         * @brief Multiplies this matrix by another matrix.
         * @param other The matrix to multiply by.
         * @return Matrix<T>& Reference to this matrix after multiplication.
         * @throws std::invalid_argument If the matrices are not compatible.
         */
        Matrix<T> &operator*=(const Matrix<T> &other)
        {
            if (m_cols != other.m_rows)
                throw std::invalid_argument("Matrix multiplication of incompatible sizes");

            Matrix<T> result(m_rows, other.m_cols);

            for (std::size_t i = 0; i < m_rows; ++i)
                for (std::size_t j = 0; j < other.m_cols; ++j)
                    for (std::size_t k = 0; k < m_cols; ++k)
                        result(i, j) += (*this)(i, k) * other(k, j);

            *this = std::move(result);

            return *this;
        }

        /**
         * @brief Multiplies this matrix by another matrix.
         * @param other The matrix to multiply by.
         * @return Matrix<T>& Reference to this matrix after multiplication.
         * @throws std::invalid_argument If the matrices are not compatible.
         */
        Matrix<T> &operator*=(Matrix<T> &&other)
        {
            if (m_cols != other.m_rows)
                throw std::invalid_argument("Matrix multiplication of incompatible sizes");

            Matrix<T> result(m_rows, other.m_cols);

            for (std::size_t i = 0; i < m_rows; ++i)
                for (std::size_t j = 0; j < other.m_cols; ++j)
                    for (std::size_t k = 0; k < m_cols; ++k)
                        result(i, j) += (*this)(i, k) * other(k, j);

            *this = std::move(result);
            return *this;
        }

        // Iterators
        /**
         * @brief
         * Gets the begin iterator of the matrix
         * @return auto The begin iterator of the matrix
         */
        auto begin()
        {
            return m_elements.begin();
        }

        /**
         * @brief
         * Gets the end iterator of the matrix
         * @return auto The end iterator of the matrix
         */
        auto end()
        {
            return m_elements.end();
        }

        /**
         * @brief
         * Gets the begin iterator of the matrix
         * @return auto The begin iterator of the matrix
         */
        auto begin() const
        {
            return m_elements.begin();
        }

        /**
         * @brief
         * Gets the end iterator of the matrix
         * @return auto The end iterator of the matrix
         */
        auto end() const
        {
            return m_elements.end();
        }

        /**
         * @brief
         * Gets the element at the specified position
         * @param row The row of the element
         * @param col The column of the element
         * @return T& The element at the specified position
         */
        T &at(std::size_t row, std::size_t col)
        {
            if (row >= m_rows || col >= m_cols)
                throw std::out_of_range("Matrix subscript out of range");

            return m_elements.at(std::make_pair(row, col));
        }

        // Methods
        /**
         * @brief
         * Gets the rows of the matrix
         * @return std::size_t The rows of the matrix
         */
        std::size_t rows() const
        {
            return m_rows;
        }

        /**
         * @brief
         * Gets the columns of the matrix
         * @return std::size_t The columns of the matrix
         */
        std::size_t cols() const
        {
            return m_cols;
        }

        /**
         * @brief
         * Gets the size of the matrix
         * @return std::size_t The size of the matrix
         */
        std::size_t size() const
        {
            return m_elements.size();
        }

        /**
         * @brief
         * Resizes the matrix
         * @param rows The new rows of the matrix
         * @param cols The new columns of the matrix
         */
        void resize(std::size_t rows, std::size_t cols)
        {
            m_rows = rows;
            m_cols = cols;
            m_elements.resize(rows * cols);
        }

        /**
         * @brief
         * Clears the matrix
         */
        void clear()
        {
            fill(T());
        }

        /**
         * @brief
         * Checks if the matrix is empty
         * @return true If the matrix is empty
         * @return false If the matrix is not empty
         */
        bool empty() const
        {
            return m_elements.empty();
        }

        /**
         * @brief
         * Fills the matrix with the specified value
         * @param value The value to fill the matrix with
         */
        void fill(const T &value)
        {
            for (auto &element : m_elements)
                element.second = value;
        }

        /**
         * @brief
         * Transposes the matrix
         * @return Matrix<T> The transposed matrix
         */
        Matrix<T> transpose() const
        {
            Matrix<T> result(m_cols, m_rows);

            for (auto &element : m_elements)
                result(element.first.second,
                       element.first.first) = element.second;

            return result;
        }

    private:
        std::size_t m_rows;
        std::size_t m_cols;
        std::unordered_map<std::pair<std::size_t, std::size_t>, T> m_elements;
    };
}