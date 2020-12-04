
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> v;
        v.insert(1);
        v.insert(n);
        for(int i=2;i<=sqrt(n);i++){
            // cout<<"value of i is: "<<i<<endl;
            if(n%i == 0){
                int kk = n / i;
                cout<<"Value of kk is : "<<kk<<endl;
                cout<<"Value of i is : "<<i<<endl;
                v.insert(i);
                v.insert(kk);
            }
        }
        int tempk = k -1;
        auto it = v.begin();
        while(it != v.end()){
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
         it = v.begin();
        for(;it != v.end() && tempk > 0;it++,tempk --){
            
        }
        if(it == v.end()){
            return -1;
        }
        return *it;
    }
};