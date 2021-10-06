#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll dp[2001][2001];

ll solve(ll &n,ll leftOut,ll prev){
    if(leftOut == 0){
        return 1;
    }

    if(dp[leftOut][prev] != -1){
        return dp[leftOut][prev];
    }

    ll ans = 0;
    for(int i=prev;i<=n;i+=prev){
        if(i%prev == 0){
            ans = (ans +  solve(n,leftOut - 1,i))%mod;
        }
    }

    dp[leftOut][prev] = ans;
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ll ans= 0;
    for(int i=1;i<=n;i++){
        ans = (ans + solve(n,k-1,i))%mod;
    }
    cout<<ans<<endl;
    return 0;
}