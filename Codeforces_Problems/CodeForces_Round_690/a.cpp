#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
// #define mod 1000000007 // equal to 10^9 + 7
// #define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll i=0;
        if(n%2 == 0){
            for(i = 0;i<n/2;i++){
                cout<<arr[i]<<" "<<arr[n - i - 1]<<" ";
            }
        }else{
            for(i = 0;i<n/2;i++){
                cout<<arr[i]<<" "<<arr[n - i - 1]<<" ";
            }
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}