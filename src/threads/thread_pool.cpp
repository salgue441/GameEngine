/**
 * @file thread_pool.h
 * @author Carlos Salguero
 * @brief Implementation of the thread pool class
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */
// C++ Standard Libraries
#include <stdexcept>
#include <memory>

// Project files
#include "thread_pool.h"

// Constructor
/**
 * @brief
 * Construct a new Thread Pool:: Thread Pool object
 * @param num_threads Number of threads to be created
 */
ThreadPool::ThreadPool(std::size_t num_threads) : m_stop(false)
{
    for (std::size_t i{}; i < num_threads; ++i)
    {
        m_threads.emplace_back([this]
                               {
            while (true)
            {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(this->m_mutex);
                    this->m_condition.wait(lock, [this]
                                           { return this->m_stop || !this->m_tasks.empty(); });

                    if (this->m_stop && this->m_tasks.empty())
                        return;

                    task = std::move(this->m_tasks.front());
                    this->m_tasks.pop();
                }

                task();
            } });
    }
}

// Destructor
/**
 * @brief
 * Destroy the Thread Pool:: Thread Pool object
 */
ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_stop = true;
    }

    m_condition.notify_all();

    for (std::thread &thread : m_threads)
        thread.join();
}