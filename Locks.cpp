#include "bits/stdc++.h"
using namespace std;

void unique_lock_thread(){
    mutex m;

    // Has ownership of mutex
    // Locks automatically and unlocks automatically when destroyed
    // Can be manually locked and unlocked
    // movable not copyable
    // Supports try_lock
    unique_lock<mutex> lock(m);

    // Do something
    cout<<"unique_lock_thread"<<endl;
}

void lock_guard_thread(){
    mutex m;

    // Has ownership of mutex
    // When std::lock_guard is created, it locks the mutex
    // If an exception occurs, std::lock_guard ensures that the mutex is released
    // Cannot be copied or moved
    lock_guard<mutex> lock(m);

    // Do something
    cout<<"lock_guard_thread"<<endl;
}


void shared_lock_thread(){
    shared_mutex smutex;

    // A shared lock allows multiple threads to read a shared resource simultaneously but prevents any thread from writing to it.
    // Also known as a "reader lock"
    // A thread cannot acquire a shared lock if another thread holds a unique (exclusive) lock.
    shared_lock<shared_mutex> slock(smutex);

    // All the shared_lock shoud be released
    unique_lock<shared_mutex> lock(smutex);
}

int main() {
    thread t1(unique_lock_thread);

    thread t2(lock_guard_thread);
}
