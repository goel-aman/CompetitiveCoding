#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[101][10001];

ll solve(vector<long long int> varr[],ll n,ll index,ll x,ll m){
    if(index == m){
        ll ans = -1;
        vector<long long int>  v(varr[index]);
        for(ll i=0;i<v.size();i++){
            if(v[i] <= x){
                ans = max(ans,v[i]);
            }
        }
        return ans;
    }

    if(dp[index][x] != -1){
        return dp[index][x]; 
    }

    vector<long long int>  v(varr[index]);
    ll ans = -1;
    for(ll i=0;i<v.size();i++){
        if(v[i] <= x){
           ll anss = solve(varr,n,index + 1, x - v[i],m);
           if(anss != -1){
               ans = max(ans, solve(varr,n,index + 1, x - v[i],m) + v[i]);
           }
        }
    }
    if(ans == -1){
        return -1;
    }
    dp[index][x] = ans;
    return ans;
}

int main(){
    ll n,m,x;
    cin>>n>>m>>x;
    ll weight_arr[n];
    for(ll i=0;i<n;i++){
        cin>>weight_arr[i];
    }
    ll color_arr[n];
    vector<long long int> varr[m+ 1];
    for(ll i=0;i<n;i++){
        cin>>color_arr[i];
        varr[color_arr[i]].push_back(weight_arr[i]);
    }
    memset(dp,-1,sizeof(dp));
    ll ans  = solve(varr,n,1,x,m);
    if(ans == -1){
        cout<<-1<<endl;
    }
    else{
    cout<<x - ans<<endl;
    }
    return 0;
}