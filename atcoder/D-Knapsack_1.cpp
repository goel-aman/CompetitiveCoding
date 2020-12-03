#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n,w;
    cin>>n>>w;
    ll value[n];
    ll weight[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>value[i];
    }
    ll dp[n][w+1] = {0};
    for(ll i=0;i<n;i++){
        dp[i][0] = 0;
    }
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=w;j++){
            if(i == 0){
                if(weight[i] > j){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = value[i];
                }
                continue;
            }
            if(j - weight[i] >= 0){
                dp[i][j] = max(dp[i-1][j],value[i] + dp[i-1][j - weight[i]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][w]<<endl;
    return 0;
}