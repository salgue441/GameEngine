/**
 * @file thread_pool.h
 * @author Carlos Salguero
 * @brief Declaration of the thread pool class
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

// C++ Standard Library
#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>

/**
 * @class ThreadPool
 * @brief Manages a trhead pool
 */
class ThreadPool
{
public:
    // Constructor
    ThreadPool(std::size_t);

    // Destructor
    ~ThreadPool();

    // Inline Methods
    /**
     * @brief
     * Add a task to the thread pool
     * @tparam F Type of the function
     * @tparam Args Type of the arguments
     * @param func Function to be executed
     * @param args Arguments of the function
     * @return std::future<typename std::result_of<F(Args...)>::type>
     *         Future of the function
     * @throw std::runtime_error If the thread pool is stopped
     */
    template <class F, class... Args>
    auto enqueue(F &&func, Args &&...args)
        -> std::future<typename std::result_of<F(Args...)>::type>
    {
        try
        {
            auto return_type = typename std::result_of<F(Args...)>::type();
            auto task = std::make_shared<std::packaged_task<return_type()>>(
                std::bind(std::forward<F>(func), std::forward<Args>(args)...));

            std::future<return_type> result = task->get_future();

            {
                std::unique_lock<std::mutex> lock(m_mutex);

                if (m_stop)
                    throw std::runtime_error(
                        "Error: The thread pool is stopped");

                m_tasks.emplace([task]()
                                { (*task)(); });
            }

            m_condition.notify_one();
            return result;
        }
        catch (const std::exception &e)
        {
            throw;
        }
    }

private:
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_tasks;
    std::mutex m_mutex;
    std::condition_variable m_condition;
    bool m_stop;
};

#endif //! THREAD_POOL_H