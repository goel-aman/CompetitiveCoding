#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solvee(ll * dp,vector<int> arr[], ll n,ll i){
    if(arr[i].size() == 0){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    ll big = INT_MIN;
    for(ll j=0;j<arr[i].size();j++){
        ll yy = solvee(dp,arr,n,arr[i][j]);
        if( yy > big){
            big = yy;
        }
    }
    dp[i] = big + 1;
    return dp[i];
}

ll solve(ll * dp,vector<int> arr[],ll n){
    ll maxx = INT_MIN;
    for(ll i=1;i<=n;i++){
        ll kk = solvee(dp,arr,n,i);
        if(kk > maxx){
            maxx = kk;
        }
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll dp[n + 1];
    for(ll i=0;i<=n;i++){
        dp[i] = -1;
    }
    vector<int> arr[n + 1];
    
    for(ll i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
    }
    
    cout<<solve(dp,arr,n)<<endl;
    return 0;
}