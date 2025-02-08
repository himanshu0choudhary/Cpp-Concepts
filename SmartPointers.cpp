#include "bits/stdc++.h"
using namespace std;

class Test{
    public:
    Test(int x){
        cout<<"Test constructor"<<endl;
    }

    ~Test(){
        cout<<"Test destructor"<<endl;
    }
};

int main() {
    // Can be moved but not copied
    // No ref count overhead
    // Automatic deallocation
    unique_ptr<Test> unique = make_unique<Test>(10);

    // Can be moved and copied
    // Ref counting(Thread safe)
    // Automatic deallocation
    shared_ptr<Test> shared1 = make_shared<Test>(10);
    shared_ptr<Test> shared2 = shared1;

    cout<<shared1.use_count()<<endl;

    // No ownership
    // Can be moved and copied
    weak_ptr<Test> weak = shared1;
    //To use it, convert
    shared_ptr<Test> weak_shared = weak.lock();
}
