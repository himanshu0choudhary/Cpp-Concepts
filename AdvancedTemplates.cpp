#include "bits/stdc++.h"
using namespace std;

// General template
template <typename T>
class MyClass
{
public:
    void show()
    {
        cout << "Generic template" << endl;
    }
};

// Specialization for `char`
template <>
class MyClass<char>
{
public:
    void show()
    {
        cout << "Specialized template for char" << endl;
    }
};





// General template
template <typename T1, typename T2>
class MyClass1 {
public:
    void show() {
        cout << "Generic template" << endl;
    }
};

// Partial specialization when the second type is `int`
template <typename T1>
class MyClass1<T1, int> {
public:
    void show() {
        cout << "Partial specialization where second type is int" << endl;
    }
};




// Generic template
template <int N>
class Factorial {
public:
    static const int value = N * Factorial<N - 1>::value;
};

// Specialization for base case (N = 0)
template <>
class Factorial<0> {
public:
    static const int value = 1;
};

int main()
{
}
