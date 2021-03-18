#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        set<int> s;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
            um[a[i]]++;
        }
        for(auto x : s){
            cout<<x<<" ";
            um[x]--;
        }

        for(auto x : um){
            if(x.second > 0){
                for(int i=0;i<x.second;i++){
                    cout<<x.first<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}