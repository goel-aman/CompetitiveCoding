#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[102][102];

ll solve(ll* red,ll*  blue,ll i,ll j,ll n,ll m){
    ll finalans = 0;
    ll ans = 0;
    if(i >= n && j >= m){
        return 0;
    }

    
    if(i >= n && j < m){
        while(j < m){
            ans+= blue[j];
            finalans = max(ans,finalans);
            j++;
        }
        return finalans;
    }

    if(j >= m && i < n){
        while(i < n){
            ans += red[i];
            finalans = max(finalans,ans);
            i++;
        }
        return finalans;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    ll first = solve(red,blue,i + 1,j,n,m);
    ll second = solve(red,blue,i,j + 1,n,m);
    finalans = max(ans,max(first + red[i],second + blue[j]));
    return (dp[i][j] = finalans);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        ll n;cin>>n;
        ll red[n];
        for(ll i=0;i<n;i++){
            cin>>red[i];
        }
        ll m;cin>>m;
        ll blue[n];
        for(ll i=0;i<m;i++)
        {
            cin>>blue[i];
        }
        ll i=0;
        ll j=0;
        cout<<solve(red,blue,0,0,n,m)<<endl;
    }
    return 0;
}