#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[101][101];
ll arr[101];
ll arrdp[101];

void fun(ll &n){
    for(int i=1;i<n;i++){
        arrdp[i] = arrdp[i] + arrdp[i-1];
    }
}

ll sum(ll start, ll end){
    if(start == 0){
        return arrdp[end] % 100;
    }
    return (arrdp[end] - arrdp[start - 1])%100;
}

ll funct(ll start,ll end){
    if(end == start){
        return 0;
    }

    if(dp[start][end] != -1){
        return dp[start][end];
    }

    ll answer = LLONG_MAX;
    for(ll i=start;i<=end - 1;i++){
        ll s = funct(start,i) + funct(i + 1, end) + sum(start,i) * sum(i + 1, end);
        if( s < answer){
            answer = s;
        }
    }
    dp[start][end] = answer;
    return dp[start][end];
}

int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF)

    {
        for(int i=0;i<n;i++){
            cin>>arrdp[i];
        }
        memset(dp,-1,sizeof(dp));
        ll answer = LLONG_MAX;
        fun(n);
        for(int i=0;i<n-1;i++){
            ll ans = funct(0,i) + funct(i+1,n-1) + sum(0,i) * sum(i+1,n-1);
            // cout<<ans<<endl;
            if(ans < answer){
                answer = ans;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}