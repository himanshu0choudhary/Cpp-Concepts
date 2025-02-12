#include "bits/stdc++.h"
using namespace std;

int main() {
    function<bool(int,int)> sort_cmp = [](int first,int second){
        return first<second;
    };
    vector<int> arr={5,8,3,56,7,4};
    sort(arr.begin(),arr.end(),sort_cmp); // Sort ascending
    // for(auto i:arr) cout<<i<<endl;



    function<bool(int,int)> pq_cmp = [](int lower,int upper){
        return lower>upper;
    };

    priority_queue<int,vector<int>,decltype(pq_cmp)> pq(pq_cmp); // Min Heap
    pq.push(5);
    pq.push(50);
    pq.push(1);
    pq.push(30);
    
    // while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }



    auto hash_fun = []<typename T1, typename T2>(const pair<T1,T2> p){
        return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
    };
    unordered_map<pair<int,string>,int,decltype(hash_fun)> umap(10,hash_fun);
    umap[{1,"x"}]=1;
    // cout<<umap[{1,"x"}]<<endl;


    unordered_map<pair<string,string>,int,decltype(hash_fun)> umap1(10,hash_fun);
    umap1[{"x","x"}]=1;
    cout<<umap1[{"x","x"}]<<endl;
}
