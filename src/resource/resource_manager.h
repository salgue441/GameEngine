/**
 * @file resource_manager.h
 * @author Carlos Salguero
 * @brief Resource Manager for the Game Engine
 * @version 0.1
 * @date 2023-07-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

// C++ Standard Library
#include <string>
#include <unordered_map>

// Project files
#include "../threads/thread_pool.h"

// Class
/**
 * @class ResourceManager
 * @brief Handles the loading and storage of resources
 */
class ResourceManager
{
public:
    // Constructors
    ResourceManager(const std::string &);
    ResourceManager(const std::string &, const std::size_t &);

    // Deleted Constructors
    ResourceManager() = delete;
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager(ResourceManager &&) = delete;

    // Destructor
    ~ResourceManager();

    // Access Methods
    const std::string &get_resource(const std::string &);
    const std::string &get_resource_path() const;

    // Deleted Operators
    ResourceManager &operator=(const ResourceManager &) = delete;
    ResourceManager &operator=(ResourceManager &&) = delete;

    // Methods
    bool resource_loaded(const std::string &);
    bool resource_exists(const std::string &);
    void load_resource(const std::string &, const std::string &);
    void unload_resource(const std::string &);

private:
    std::string m_resource_path;
    std::unordered_map<std::string, std::pair<std::string, int>> m_resources;
    ThreadPool m_thread_pool;

    // Methods
    void load_resource_thread(const std::string &, const std::string &);
};

#endif //! RESOURCE_MANAGER_H