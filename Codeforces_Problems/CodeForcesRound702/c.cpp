#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int ans = 0;
        for(ll i=1;i<=cbrt(n);i++){
            ll value = i * i * i;
            ll leftOut = n - value;
            if(leftOut > 0){
                ll secondVal = cbrt(leftOut);
                if(secondVal * secondVal * secondVal == leftOut){
                    ans = 1;
                    break;
                }
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}