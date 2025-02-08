#include "bits/stdc++.h"
using namespace std;

// Separate function for processing even numbers
void countEvenNumbers(promise<int> EvenPromise, int begin, int end)
{
    int evenNo = 0;
    for (int i = begin; i <= end; i++)
    {
        if (i % 2 == 0)
        {
            evenNo += 1;
        }
    }
    EvenPromise.set_value(evenNo); // Set the result
}

int main()
{
    // Create a promise
    promise<int> even_promise;

    // Get corresponding future
    future<int> even_future = even_promise.get_future();

    
    thread t1(countEvenNumbers, std::move(even_promise), 0, 10);

    cout << even_future.get() << endl;

    // Call join for proper cleanup otherwise programme may crash
    t1.join();

    return 0;
}
