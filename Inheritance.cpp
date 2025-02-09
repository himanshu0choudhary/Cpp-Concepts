#include "bits/stdc++.h"
using namespace std;

// Useful keywords
// const	    Prevents modification of a member function or variable.
// override	Ensures a function correctly overrides a base class function.
// final	    Prevents further overriding or inheritance.
// mutable	    Allows modification of a variable in a const function.
// explicit	Prevents implicit type conversions.
// static	    Shares a variable across all objects or makes a function independent of instances.
// constexpr	Evaluates expressions at compile time.
// virtual	    Enables runtime polymorphism.

// Abstract class
// Its an interface if it has only pure virtual methods
class PureVirtual
{
public:
    // Pure virtual methods
    virtual void method1() = 0;
    virtual void method2() = 0;

    virtual ~PureVirtual() {}

    virtual void method3() const final
    {
        cout << "PureVirtual: method3" << endl;
    }

    void method4()
    {
        cout << "PureVirtual: method4" << endl;
    }
};

// If you want make an instance of this class
// Implememnt all non implemented functions
class Derived : public PureVirtual
{
public:
    void method1() override
    {
        cout << "Derived: method1" << endl;
    }

    void method2() override
    {
        cout << "Derived: method2" << endl;
    }

    // void method4() override{} // Error, only non final virtual function can be overridden
};

int main()
{
    Derived d;
    // d.method3(); // Output: PureVirtual: method3

    // PureVirtual p = Derived(); // Not allowed like java
    PureVirtual *ptr = new Derived();
    // ptr->method4(); // Output: PureVirtual: method4

    PureVirtual &&p1 = Derived();
    // p1.method4(); // Output: PureVirtual: method4

    // PureVirtual& p=Derived(); // Error
}
