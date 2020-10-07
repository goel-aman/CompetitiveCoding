#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long int

ll dp[1001][1001];

ll solve(ll * weight,ll * value,ll n,ll capacity,ll index){
    if(capacity <= 0){
        return 0;
    }
    if(index >= n){
        return 0;
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    ll ans = 0;
    if(weight[index] <= capacity){
        ans = value[index] + solve(weight,value,n,capacity - weight[index],index + 1);
    }

    ans = max(ans,solve(weight,value,n,capacity,index + 1));
    dp[index][capacity] = ans;
    return ans;
}

int main(){
    ll n,capacity;
    cin>>n>>capacity;
    ll weight[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    ll value[n];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(weight,value,n,capacity,0)<<endl;
    return 0;
}