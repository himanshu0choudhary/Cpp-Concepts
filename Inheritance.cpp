#include "bits/stdc++.h"
using namespace std;

// Abstract class
// Its an interface if it has only pure virtual methods
class PureVirtual{
    public:
    // Pure virtual methods
    virtual void method1() = 0;
    virtual void method2() = 0;

    virtual ~PureVirtual() {}

    virtual void method3(){
        cout<<"PureVirtual: method3"<<endl;
    }

    void method4(){
        cout<<"PureVirtual: method4"<<endl;
    }
};

// If you want make an instance of this class
// Implememnt all non implemented functions
class Derived: public PureVirtual{
    public:
    void method1() override {
        cout<<"Derived: method1"<<endl;
    }

    void method2() override {
        cout<<"Derived: method2"<<endl;
    }
};

int main() {
    Derived d;
    // d.method3(); // Output: PureVirtual: method3

    // PureVirtual p = Derived(); // Not allowed like java
    PureVirtual *ptr = new Derived();
    // ptr->method4(); // Output: PureVirtual: method4

    PureVirtual&& p1=Derived();
    // p1.method4(); // Output: PureVirtual: method4

    //PureVirtual& p=Derived(); // Error
}
