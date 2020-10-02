#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin>>t;
    while(t--){
        ll n,l;
        cin>>n>>l;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll counter = 0;
        ll i = 0;
        ll j = l;
        ll speedi = 1;
        ll speedj = 1;
        while(i < j){
            
            i = i + speedi;
            j = j + speedj;
        }
    }
    return 0;
}