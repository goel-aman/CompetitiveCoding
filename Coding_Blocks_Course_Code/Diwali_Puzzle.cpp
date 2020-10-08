#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000003
// index prev target

ll dp[101][2][101];

ll funct(ll prev, ll n,ll index,ll value,ll &target){
    if(index == n){
        if(value == target){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[index][prev][value] != -1)
    {
        return dp[index][prev][value];
    }

    ll ans = 0;
    if(prev == 1){
        ans += funct(1,n,index + 1,value + 1 , target);
    }else{
        ans += funct(1,n,index + 1,value,target);
    }
    ans %= mod;
    ans += funct(0,n,index + 1, value,target);
    ans %= mod;
    dp[index][prev][value] = ans;
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        ll target;
        cin>>n>>target;
        memset(dp,-1,sizeof(dp));

        ll ans = funct(0,n,0,0,target);
        cout<<ans%mod<<endl;
    }
    return 0;
}