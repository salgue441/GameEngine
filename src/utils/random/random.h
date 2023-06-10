/**
 * @file random.h
 * @author Carlos Salguero
 * @brief Declaration of the template class for the random engine
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

// C++ Standard Libraries
#include <random>
#include <chrono>

// Project files
#include "../math/vector.h"
#include "../color/color.h"

namespace Math
{
    /**
     * @class RandomEngine
     * @brief Template class for the random engine
     */
    template <class T>
    class RandomEngine
    {
    public:
        // Consturctors
        RandomEngine() = default;

        /**
         * @brief
         * Construct a new Random Engine object
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         */
        RandomEngine(const T &min, const T &max)
        {
            auto seed =
                std::chrono::high_resolution_clock::now()
                    .time_since_epoch()
                    .count();
            m_engine.seed(seed);

            m_distribution = std::uniform_real_distribution<T>(min, max);
        }

        /**
         * @brief
         * Construct a new Random Engine object.
         * @tparam T Type of the random number
         * @param other Other random engine
         * @details Copy constructor
         */
        RandomEngine(const RandomEngine &other) = default;

        /**
         * @brief
         * Construct a new Random Engine object
         * @tparam T Type of the random number
         * @param other Other random engine
         * @details Move constructor
         */
        RandomEngine(RandomEngine &&other)
        {
            m_engine = std::move(other.m_engine);
            m_distribution = std::move(other.m_distribution);
        }

        // Destructor
        ~RandomEngine() = default;

        // Operators
        RandomEngine &operator=(const RandomEngine &other) = default;
        RandomEngine &operator=(RandomEngine &&other) = default;

        // Access Methods
        /**
         * @brief
         * Get a random number
         * @tparam T Type of the random number
         * @return A random number
         */
        T get_random_number()
        {
            return m_distribution(m_engine);
        }

        /**
         * @brief
         * Get a random number
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         * @return A random number
         */
        T get_random_number(const T &min, const T &max)
        {
            m_distribution = std::uniform_real_distribution<T>(min, max);
            return m_distribution(m_engine);
        }

        // Methods
        /**
         * @brief
         * Gets a random integer number
         * @tparam T Type of the random number
         * @return A random integer number
         */
        int get_random_int()
        {
            return static_cast<int>(m_distribution(m_engine));
        }

        /**
         * @brief
         * Gets a random integer number
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         * @return A random integer number
         */
        int get_random_int(const int &min, const int &max)
        {
            m_distribution = std::uniform_real_distribution<T>(min, max);
            return static_cast<int>(m_distribution(m_engine));
        }

        /**
         * @brief
         * Gets a random float number
         * @tparam T Type of the random number
         * @return A random float number
         */
        float get_random_float()
        {
            return static_cast<float>(m_distribution(m_engine));
        }

        /**
         * @brief
         * Gets a random float number
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         * @return A random float number
         */
        float get_random_float(const float &min, const float &max)
        {
            m_distribution = std::uniform_real_distribution<T>(min, max);
            return static_cast<float>(m_distribution(m_engine));
        }

        /**
         * @brief
         * Gets a random boolean value
         * @tparam T Type of the random number
         * @return A random boolean value
         */
        bool get_random_bool()
        {
            return static_cast<bool>(m_distribution(m_engine));
        }

        /**
         * @brief
         * Gets a random boolean value
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         * @return A random boolean value
         */
        bool get_random_bool(const bool &min, const bool &max)
        {
            m_distribution = std::uniform_real_distribution<T>(min, max);
            return static_cast<bool>(m_distribution(m_engine));
        }

        /**
         * @brief
         * Generates a random 2D vector within a specified range
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         * @return A random 2D vector
         */
        Math::Vector<T> get_random_vector2D(const T &min, const T &max)
        {
            m_distribution = std::uniform_real_distribution<T>(min, max);
            return Math::Vector<T>(
                m_distribution(m_engine),
                m_distribution(m_engine));
        }

        /**
         * @brief
         * Generates a random 3d vector within a specified range
         * @tparam T Type of the random number
         * @param min Minimum value of the random number
         * @param max Maximum value of the random number
         * @return A random 3D vector
         */
        Math::Vector<T> get_random_vector3D(const T &min, const T &max)
        {
            m_distribution = std::uniform_real_distribution<T>(min, max);
            return Math::Vector<T>(
                m_distribution(m_engine),
                m_distribution(m_engine),
                m_distribution(m_engine));
        }

        /**
         * @brief
         * Generates a random 2d direction vector with a length of 1
         * @tparam T Type of the random number
         * @return A random 2D direction vector
         */
        Math::Vector<T> get_random_direction_vector2D()
        {
            return Math::Vector<T>(
                       m_distribution(m_engine),
                       m_distribution(m_engine))
                .normalize();
        }

        /**
         * @brief
         * Generates a random 3d direction vector with a length of 1
         * @tparam T Type of the random number
         * @return A random 3D direction vector
         */
        Math::Vector<T> get_random_direction_vector3D()
        {
            return Math::Vector<T>(
                       m_distribution(m_engine),
                       m_distribution(m_engine),
                       m_distribution(m_engine))
                .normalize();
        }

        /**
         * @brief
         * Shuffles the elements of an array randomly.
         * @tparam T Type of the random number
         * @param array Array to shuffle
         * @param size Size of the array
         */
        void shuffle_array(T *array, const size_t &size)
        {
            for (size_t i = 0; i < size; i++)
            {
                size_t random_index = get_random_int(0, size - 1);
                std::swap(array[i], array[random_index]);
            }
        }

        /**
         * @brief
         * Shuffles the elements of a vector randomly.
         * @tparam T Type of the random number
         * @param vector Vector to shuffle
         */
        void shuffle_vector(std::vector<T> &vector)
        {
            for (size_t i = 0; i < vector.size(); i++)
            {
                size_t random_index = get_random_int(0, vector.size() - 1);
                std::swap(vector[i], vector[random_index]);
            }
        }

        /**
         * @brief
         * Generates a random color value.
         * @tparam T Type of the random number
         * @return A random color value
         */
        template <class T>
        Color<T> get_random_color()
        {
            return Math::Color<T>(
                m_distribution(m_engine),
                m_distribution(m_engine),
                m_distribution(m_engine),
                m_distribution(m_engine));
        }

        /**
         * @brief
         * Generates a random rotation value
         * @tparam T Type of the random number
         * @return A random rotation value
         */
        template <class T>
        Math::Quaternion<T> get_random_rotation()
        {
            return Math::Quaternion<T>(
                m_distribution(m_engine),
                m_distribution(m_engine),
                m_distribution(m_engine),
                m_distribution(m_engine));
        }

    private:
        std::mt19937_64 m_engine;
        std::uniform_real_distribution<T> m_distribution;
    };
} // namespace Math