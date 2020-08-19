#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class weight_value{
    public:
    ll weight;
    ll value;
};

int main(){
    ll n,w;
    cin>>n>>w;
    weight_value input[n];
    for(ll i=0;i<n;i++){
        cin>>input[i].weight;
        cin>>input[i].value;
    }
    ll maxValue = n * 1000;
    ll dp[n][maxValue + 1];
    for(ll i=0;i<n;i++){
        dp[i][0] = 0;
    }
    for(ll i=1;i<=maxValue;i++){
        dp[0][i] = INT_MAX;
    }
    dp[0][input[0].value] = input[0].weight;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=maxValue;j++){
            if(j - input[i].value < 0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = min(dp[i-1][j], input[i].weight + dp[i-1][j - input[i].value]);
        }
    }
    ll ans = 0;
    for(ll i=1;i<=maxValue;i++){
        if(i > ans && dp[n-1][i] <= w){
            ans = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}