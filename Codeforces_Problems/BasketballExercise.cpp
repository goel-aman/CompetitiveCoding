#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// C. Basketball Exercise

ll dp[100001][3];

// prev -> 0 means firstArray was consumed,1 means 2nd array was consumed, -1 no array element was consumed. 
ll team(vector<ll>& firstArray,vector<ll>& secondArray,ll index,ll &n,ll prev){
    if(index == n){
        return 0;
    }

    if(dp[index][prev] != -1){
        return dp[index][prev];
    }

    ll first = LLONG_MIN,second = LLONG_MIN,third = LLONG_MIN;
    if(prev == 0 || prev == 2){
        second = secondArray[index] +  team(firstArray,secondArray,index + 1,n,1);
    }

    if(prev == 1 || prev == 2){
        first = firstArray[index] + team(firstArray,secondArray,index + 1,n,0);
    }

    third = team(firstArray,secondArray,index + 1,n,2);

    return dp[index][prev] = max({first,second,third});
}

int main(){
    ll n;
    cin>>n;
    vector<ll> firstArray(n);
    vector<ll> secondArray(n);

    for(ll i=0;i<n;i++){
        cin>>firstArray[i];
    }

    for(ll j=0;j<n;j++){
        cin>>secondArray[j];
    }
    memset(dp,-1,sizeof(dp));
    ll prev = -1;
    ll ans = team(firstArray,secondArray,0,n,2);
    cout<<ans<<endl;
    return 0;
}