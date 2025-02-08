#include "bits/stdc++.h"
using namespace std;

class ThreadPool
{
public:
    ThreadPool(unsigned int num_threads)
    {
        this->pool_size = num_threads;

        for (unsigned int i = 0; i < num_threads; ++i)
        {
            threads.emplace_back([this]
                                 {
                function<void()> task;

                while (true)
                {
                    {
                        // Has ownership of mutex
                        // Locks automatically and unlocks automatically when destroyed
                        // Can be manually locked and unlocked
                        // movable not copyable
                        // Supports try_lock
                        // Locks on queue_mutex
                        unique_lock<mutex> lock(queue_mutex);

                        // Automatically unlocks lock while waiting
                        // Supports notify_one and notify_all
                        // If multiple threads are waiting, any of them can be woken up randomly.
                        // Can be used to wait for a condition with a timeout
                        cv.wait(lock, [this]
                                { return !task_queue.empty() or stop; });

                        if (stop and task_queue.empty())
                            return;

                        task = task_queue.front();
                        task_queue.pop();
                    }
                    
                    task();
                } });
        }
    }

    ~ThreadPool()
    {
        {
            unique_lock<mutex> lock(queue_mutex);
            stop = true;
        }

        cv.notify_all();

        for (auto &thread : threads)
        {
            thread.join();
        }
    }

    void enqueue(function<void()> task)
    {
        {
            unique_lock<mutex> lock(queue_mutex);
            task_queue.emplace(task);
        }
        cv.notify_one();
    }

private:
    unsigned int pool_size;

    vector<thread> threads;

    queue<function<void()>> task_queue;

    mutex queue_mutex;

    condition_variable cv;

    bool stop = false;
};

int main()
{
    ThreadPool pool(5);

    for (int i = 0; i < 10; ++i)
    {
        pool.enqueue([i]
                     {
            cout << "Task " << i << " is running on thread "
                 << this_thread::get_id() << endl;
            this_thread::sleep_for(
                chrono::milliseconds(100)); });
    }
}