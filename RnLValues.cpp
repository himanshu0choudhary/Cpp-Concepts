#include "bits/stdc++.h"
using namespace std;

class MyClassCopy
{
public:
    string data;

    // & - LValue reference
    // By using std::move it can also work as as move constructor
    // Use for copying
    MyClassCopy(const MyClassCopy &other)
    {
        data = other.data;
    }
};

class MyClassMove
{
public:
    string data;

    MyClassMove(string data){
        this->data=std::move(data);
    }

    // && - RValue reference
    // & can be also used here rather then && (works fine)
    // Use for moving
    MyClassMove(MyClassMove &&other) noexcept
    {
        data = std::move(other.data);
    }
};

int main()
{
    // RValue is {1,2,3}
    // LValue is v1
    // A constructor is needed to assign RValue to LValue
    vector<int> v1 = {1, 2, 3};

    // Here Rvalue is directly assigned
    // A Move Constructor or Move Assignment
    vector<int> v2 = std::move(v1);

    // cout << v1.size() << endl; // 0
    // cout << v2.size() << endl; // 3

    MyClassMove m1("MyClassMove");

    MyClassMove m2(std::move(m1));

    cout<<m1.data.size()<<endl; // 0
    cout<<m2.data.size()<<endl; // 11
}