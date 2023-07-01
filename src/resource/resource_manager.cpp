/**
 * @file resource_manager.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Resource Manager
 * @version 0.1
 * @date 2023-07-01
 *
 * @copyright Copyright (c) 2023
 *
 */

// C++ Standard Library
#include <fstream>
#include <iostream>
#include <thread>
#include <sstream>

// Project files
#include "resource_manager.h"

// Constructors
/**
 * @brief
 * Construct a new Resource Manager:: Resource Manager object
 * @param resource_path Path to the resources folder
 */
ResourceManager::ResourceManager(const std::string &resource_path)
    : m_resource_path(resource_path),
      m_thread_pool(std::thread::hardware_concurrency())
{
}

/**
 * @brief
 * Construct a new Resource Manager:: Resource Manager object
 * @param resource_path Path to the resources folder
 * @param thread_count Number of threads to use
 */
ResourceManager::ResourceManager(const std::string &resource_path, const std::size_t &thread_count)
    : m_resource_path(resource_path), m_thread_pool(thread_count)
{
}

// Destructor
/**
 * @brief
 * Destroy the Resource Manager:: Resource Manager object
 */
ResourceManager::~ResourceManager()
{
    auto it = m_resources.begin();

    while (it != m_resources.end())
        it = m_resources.erase(it);

    m_resources.clear();
}

// Access Methods
/**
 * @brief
 * Get the resource path
 * @return const std::string& Path to the resources folder
 */
const std::string &ResourceManager::get_resource_path() const
{
    return m_resource_path;
}

/**
 * @brief
 * Get the resource
 * @param resource_name Name of the resource
 * @return const std::string& Path to the resource
 */ 
const std::string &ResourceManager::get_resource(
    const std::string &resource_name)
{
    return m_resources[resource_name].first;
}

// Methods
/**
 * @brief
 * Check if a resource is loaded
 * @param resource_name Name of the resource
 * @return true Resource is loaded
 * @return false Resource is not loaded
 */
bool ResourceManager::resource_loaded(const std::string &resource_name)
{
    return m_resources.find(resource_name) != m_resources.end();
}

/**
 * @brief
 * Check if a resource exists
 * @param resource_name Name of the resource
 * @return true Resource exists
 * @return false Resource does not exist
 */
bool ResourceManager::resource_exists(const std::string &resource_name)
{
    std::ifstream file(m_resource_path + resource_name);

    return file.good();
}

/**
 * @brief
 * Load a resource into memory. If the resource is already loaded, it will
 * increase the reference count. If the resource does not exist, it will throw
 * an exception.
 * @param resource_name Name of the resource
 * @param resource_path Path to the resource
 * @throw std::runtime_error Resource does not exist
 */
void ResourceManager::load_resource(const std::string &resource_name,
                                    const std::string &resource_path)
{
    if (resource_loaded(resource_name))
    {
        m_resources[resource_name].second++;
        return;
    }

    std::ifstream file(m_resource_path + resource_path);

    if (!file.good())
        throw std::runtime_error("Resource does not exist");

    std::stringstream buffer;
    buffer << file.rdbuf();

    m_resources[resource_name] = std::make_pair(buffer.str(), 1);
}

/**
 * @brief
 * Unload a resource
 * @param resource_name Name of the resource
 */
void ResourceManager::unload_resource(const std::string &resource_name)
{
    auto it = m_resources.find(resource_name);

    if (it == m_resources.end())
        return;

    auto &resource = it->second;
    resource.second--;

    if (resource.second == 0)
        m_resources.erase(it);
}