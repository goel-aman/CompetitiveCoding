#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// prev - 1 means she was in gym.
// prev - 0 means she was in contest;
// prev - 2 means she had rest;

ll dp[101][3];

ll solve(ll * a,ll index,ll prev,ll n){
    if(index == n){
        return 0;
    }

    if(dp[index][prev] != -1){
        return dp[index][prev];
    }

    ll ans = 0;
    if(a[index] == 0){
        ans = 1 + solve(a,index + 1,2,n);
        return dp[index][prev] = ans;
    }

    if(a[index] == 1 && prev == 0){
        ans = 1 + solve(a,index + 1,2,n);
        return dp[index][prev] = ans;
    }

    if(a[index] == 1 && prev != 0){
        ans = solve(a,index + 1,0,n);
        return dp[index][prev] = ans;
    } 

    if(a[index] == 2 && prev == 1){
        ans = 1 + solve(a,index + 1,2,n);
        return dp[index][prev] = ans;
    }

    if(a[index] == 2 && prev != 1){
        ans = solve(a,index + 1,1,n);
        return dp[index][prev] = ans;
    }

    if(a[index] == 3 && prev == 2){
        ans = min(solve(a,index + 1,1,n),solve(a,index + 1,0,n));
        return dp[index][prev] = ans;
    }

    if(a[index] == 3 && prev == 0){
        ans = solve(a,index + 1,1,n);
        return dp[index][prev] = ans;
    }

    if(a[index] == 3 && prev == 1){
        ans = solve(a,index + 1,0,n);
        return dp[index][prev] = ans;
    }
    return 0;
}

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(a,0,2,n);
    cout<<ans<<endl;
    return 0;
}