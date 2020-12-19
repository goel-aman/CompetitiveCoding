#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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
        sort(arr,arr + n);
        ll s = n / 2;
        for(ll i=0;i<n;i++){
            cout<<arr[s]<<" ";
        }
        cout<<endl;
    }
    return 0;
}