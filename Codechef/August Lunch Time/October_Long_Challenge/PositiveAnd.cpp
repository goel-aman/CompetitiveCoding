#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        if(__builtin_popcount(n) == 1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> v;
        vector<int> vv;
        for(int i=1;i<=n;i++){
            if(__builtin_popcount(i) == 1){
                vv.push_back(i);
                continue;
            }
            v.push_back(i);
        }
            // for(auto y: v){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
        for(auto x: vv)
        {
            // cout<<"x is : "<<x<<endl;
            for(ll i=-1;i<v.size();i++){
                if(i == -1){
                    if(x == 1){
                        continue;
                    }
                    if((x&v[0])){
                        auto it = v.begin();
                        v.insert(it,x);
                        break;
                    }
                }
                if(i == v.size()-1){
                    if((x&v[i])){
                        auto it = v.begin();
                        v.insert(it + i + 1,x);
                        break;
                    }
                    
                }
                if((x&v[i]) && (x&v[i+1])){
                    auto it = v.begin();
                    v.insert(it + i + 1,x);
                    break;
                }
            }
            // for(auto y: v){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
        }
        for(auto y: v){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}