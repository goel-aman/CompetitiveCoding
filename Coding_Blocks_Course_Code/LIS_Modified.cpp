#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

ll dp[200001];

ll lis(ll * arr,ll* weights, ll n){
    ll ans = INT_MIN;
    for(ll i = n - 1;i>= 0;i--){
        dp[i] = weights[i];
        ll val = INT_MIN;
        for(ll j=i+1;j<n;j++){
            if(arr[j] > arr[i]){
                if(dp[j] > val){
                    val = dp[j];
                }
            }
        }
        if(val > 0){
            dp[i] += val;
        }

        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    return ans;
}

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
        ll weights[n];
        for(ll i=0;i<n;i++){
            cin>>weights[i];
        }
        cout<<lis(arr,weights,n)<<endl;
    }
    return 0;
}