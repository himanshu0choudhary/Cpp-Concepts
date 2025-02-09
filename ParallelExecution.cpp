#include "bits/stdc++.h"
using namespace std;

int compute(int x) {
    return x;
}

void task(promise<int> p, int x) {  // Pass promise by move
    p.set_value(compute(x));
}

int main() {
    promise<int> p;
    future<int> result1 = p.get_future();
    thread t1(task, std::move(p), 10);
    t1.join();
    cout << "Thread: " << result1.get() << endl;



    future<int> result2 = async(launch::async, compute, 20);
    cout << "Async: " << result2.get() << endl;

    
    
    packaged_task<int(int)> task(compute);
    future<int> result3 = task.get_future();
    
    thread t2(std::move(task), 30);
    t2.join();
    
    cout << "Packaged Task: " << result3.get() << endl;
}
