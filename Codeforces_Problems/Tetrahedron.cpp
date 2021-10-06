#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

// E. Tetrahedron
// 0->non-D, 1 - D

ll dp[10000005][2];

int main(){
    ll n;
    cin>>n;
    // memset(dp,-1,sizeof(dp));
    dp[0][1] = 1;
    dp[0][0] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    for(ll i=2;i<=n;i++){
        dp[i][1] = ((long long int) 3 * dp[i - 1][0])%mod;
        dp[i][0] = (dp[i - 1][1]%mod + ((long long int)2 * dp[i - 1][0])%mod)%mod;
    }
    cout<<dp[n][1]<<endl;   
}