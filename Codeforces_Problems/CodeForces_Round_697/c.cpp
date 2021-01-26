#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll nc2(ll n){
    if(n <= 1){
        return 0;
    }
    return (n*(n - 1))/2;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,k;
        cin>>a>>b>>k;
        ll boys[a + 1] = {0};
        for(ll i=0;i<k;i++){
            ll boy;
            cin>>boy;
            boys[boy] += 1;
        }
        ll girls[b + 1] = {0};
        for(ll i=0;i<k;i++){
            ll girl;
            cin>>girl;
            girls[girl] += 1;
        }
        ll ans = nc2(k);
        for(ll i=1;i<=a;i++){
            ans -= nc2(boys[i]);
        }

        for(ll i=1;i<=b;i++){
            ans -= nc2(girls[i]);
        }
        cout<<ans<<endl;
    }
}
