#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        ll mini = INT_MAX;
        unordered_map<ll,ll> um;
        for(ll i=0;i<n;i++){
            cin>>a[i]; 
            um[a[i]]++;
            if(a[i] < mini){
                mini = a[i];
            }
        }
        cout<<n-um[mini]<<endl;
    }
}