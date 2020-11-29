#include<bits/stdc++.h>
using namespace std;
#define ll long long int



ll solve(ll arr[],ll n,ll k,set<ll> s){
    ll ans = LONG_MAX;
    // ll days = 0;
    for(auto val : s){
        ll i = 0;
        ll days = 0;
        while(i<n){
            if(arr[i] == val){
               i++;
               continue; 
            }
            days++;
            i = i + k;
        }
        if(days < ans){
            ans = days;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        set<ll> s;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }
        cout<<solve(arr,n,k,s)<<endl;
    }
    return 0;
}