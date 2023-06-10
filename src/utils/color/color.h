/**
 * @file color.h
 * @author Carlos Salguero
 * @brief Declaration and implementation of the template class for the color
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

// C++ Standard Libraries
#include <string>

/**
 * @class Color
 * @brief Template class for the color
 * @tparam T Type of the color
 */
template <class T>
class Color
{
public:
    // Constructors
    Color() = default;

    /**
     * @brief
     * Construct a new Color object
     * @tparam T Type of the color
     * @param red Red color
     * @param green Green color
     * @param blue Blue color
     */
    Color(const T &red, const T &green, const T &blue)
        : m_red(red), m_green(green), m_blue(blue) {}

    /**
     * @brief
     * Construct a new Color object
     * @tparam T Type of the color
     * @param red Red color
     * @param green Green color
     * @param blue Blue color
     * @param alpha Alpha color
     */
    Color(const T &red, const T &green, const T &blue, const T &alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

    /**
     * @brief
     * Construct a new Color object
     * @tparam T Type of the color
     * @param other Other color
     * @details Copy constructor
     */
    Color(const Color &other) = default;

    // Destructor
    ~Color() = default;

    // Getters
    /**
     * @brief
     * Get the red color
     * @tparam T Type of the color
     * @return T Red color
     */
    T get_red() const
    {
        return m_red;
    }

    /**
     * @brief
     * Get the green color
     * @tparam T Type of the color
     * @return T Green color
     */
    T get_green() const
    {
        return m_green;
    }

    /**
     * @brief
     * Get the blue color
     * @tparam T Type of the color
     * @return T Blue color
     */
    T get_blue() const
    {
        return m_blue;
    }

    /**
     * @brief
     * Get the alpha color
     * @tparam T Type of the color
     * @return T Alpha color
     */
    T get_alpha() const
    {
        return m_alpha;
    }

    // Setters
    /**
     * @brief
     * Set the red color
     * @tparam T Type of the color
     * @param red Red color
     */
    void set_red(const T &red)
    {
        m_red = red;
    }

    /**
     * @brief
     * Set the green color
     * @tparam T Type of the color
     * @param green Green color
     */
    void set_green(const T &green)
    {
        m_green = green;
    }

    /**
     * @brief
     * Set the blue color
     * @tparam T Type of the color
     * @param blue Blue color
     */
    void set_blue(const T &blue)
    {
        m_blue = blue;
    }

    /**
     * @brief
     * Set the alpha color
     * @tparam T Type of the color
     * @param alpha Alpha color
     */
    void set_alpha(const T &alpha)
    {
        m_alpha = alpha;
    }

    // Operators
    Color &operator=(const Color &other) = default;

    /**
     * @brief
     * Adds the color to the current color
     * @param other Other color
     * @return Color& Current color
     */
    Color &operator+=(const Color &other)
    {
        m_red += other.m_red;
        m_green += other.m_green;
        m_blue += other.m_blue;
        m_alpha += other.m_alpha;

        return *this;
    }

    /**
     * @brief
     * Subtracts the color to the current color
     * @param other Other color
     * @return Color& Current color
     */
    Color &operator-=(const Color &other)
    {
        m_red -= other.m_red;
        m_green -= other.m_green;
        m_blue -= other.m_blue;
        m_alpha -= other.m_alpha;

        return *this;
    }

    /**
     * @brief
     * Multiplies the color to the current color
     * @param other Other color
     * @return Color& Current color
     */
    Color &operator*=(const Color &other)
    {
        m_red *= other.m_red;
        m_green *= other.m_green;
        m_blue *= other.m_blue;
        m_alpha *= other.m_alpha;

        return *this;
    }

    /**
     * @brief
     * Divides the color to the current color
     * @param other Other color
     * @return Color& Current color
     */
    Color &operator/=(const Color &other)
    {
        m_red /= other.m_red;
        m_green /= other.m_green;
        m_blue /= other.m_blue;
        m_alpha /= other.m_alpha;

        return *this;
    }

    /**
     * @brief
     * Adds the color to the current color
     * @param other Other color
     * @return Color Current color
     */
    Color operator+(const Color &other) const
    {
        return Color(*this) += other;
    }

    /**
     * @brief
     * Subtracts the color to the current color
     * @param other Other color
     * @return Color Current color
     */
    Color operator-(const Color &other) const
    {
        return Color(*this) -= other;
    }

    /**
     * @brief
     * Multiplies the color to the current color
     * @param other Other color
     * @return Color Current color
     */
    Color operator*(const Color &other) const
    {
        return Color(*this) *= other;
    }

    /**
     * @brief
     * Divides the color to the current color
     * @param other Other color
     * @return Color Current color
     */
    Color operator/(const Color &other) const
    {
        return Color(*this) /= other;
    }

    /**
     * @brief
     * Compares the color to the current color
     * @param other Other color
     * @return true If the colors are equal
     * @return false If the colors are not equal
     */
    bool operator==(const Color &other) const
    {
        return m_red == other.m_red && m_green == other.m_green &&
               m_blue == other.m_blue && m_alpha == other.m_alpha;
    }

    /**
     * @brief
     * Compares the color to the current color
     * @param other Other color
     * @return true If the colors are not equal
     * @return false If the colors are equal
     */
    bool operator!=(const Color &other) const
    {
        return !(*this == other);
    }

    // Methods
    /**
     * @brief
     * Converts the color to a string
     * @return std::string String representation of the color
     */
    std::string to_string() const
    {
        std::stringstream ss;

        ss << "Color(" << m_red << ", " << m_green << ", " << m_blue << ", "
           << m_alpha << ")";

        return ss.str();
    }

private:
    T m_red;
    T m_green;
    T m_blue;
    T m_alpha;
};