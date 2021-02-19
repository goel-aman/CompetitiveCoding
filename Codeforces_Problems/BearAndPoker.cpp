#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        while(a[i]%2 == 0){
            a[i] = a[i] / 2;
        }

        while(a[i]%3 == 0){
            a[i] = a[i] / 3;
        }
    }
    bool ans = 1;
    ll val = a[0];
    for(ll i=1;i<n;i++){
        if(a[i] != val){
            ans = 0;
            break;
        }
    }

    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}