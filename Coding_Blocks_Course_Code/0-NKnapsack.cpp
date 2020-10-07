#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[1001][1001];

ll funct(ll * weight_arr,ll * value_arr,ll n,ll capacity,ll index){
    if(index >= n){
        return 0;
    }

    if(capacity <= 0){
        return 0;
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    ll ans = 0;
    if(weight_arr[index] <= capacity){
        ll j = (capacity / weight_arr[index]);
        for(ll i = 1;i<=j;i++){
            ans =max(ans,value_arr[index] * i + funct(weight_arr,value_arr,n,(capacity - (weight_arr[index] * i)),index + 1) );
        }
    }
    ans = max(ans,funct(weight_arr,value_arr,n,capacity,index + 1));
    dp[index][capacity] = ans;
    return ans;
}

int main(){
    ll n;
    cin>>n;
    ll capacity;
    cin>>capacity;
    ll weight_arr[n];
    for(int i=0;i<n;i++){
        cin>>weight_arr[i];
    }

    ll value_arr[n];
    for(int i=0;i<n;i++){
        cin>>value_arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<funct(weight_arr,value_arr,n,capacity,0);
    return 0;
}