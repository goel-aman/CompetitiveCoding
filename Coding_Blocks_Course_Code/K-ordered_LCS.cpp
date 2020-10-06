#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[2001][2001][6];
vector<long long int> v1;
vector<long long int> v2;

ll lcs_twist(ll i_vone,ll j_vtwo,ll v_one_length,ll v_two_length,ll k){
    if(i_vone > v_one_length || j_vtwo > v_two_length){
        return 0;
    }

    if(dp[i_vone][j_vtwo][k] != -1){
        return dp[i_vone][j_vtwo][k];
    }

    if(v1[i_vone] == v2[j_vtwo]){
        ll ans =  (lcs_twist(i_vone + 1,j_vtwo + 1,v_one_length,v_two_length,k) + 1);
        dp[i_vone][j_vtwo][k] = ans;
        return ans;
    }

    if(k > 0){
        ll ans = max( (lcs_twist(i_vone + 1,j_vtwo + 1,v_one_length,v_two_length,k - 1) + 1)  , max(lcs_twist(i_vone + 1, j_vtwo,v_one_length,v_two_length,k),lcs_twist(i_vone,j_vtwo + 1,v_one_length,v_two_length,k)));
        dp[i_vone][j_vtwo][k] = ans;
        return ans;
    }

    ll ans = max(lcs_twist(i_vone + 1,j_vtwo,v_one_length,v_two_length,k), lcs_twist(i_vone,j_vtwo + 1,v_one_length,v_two_length,k));
    dp[i_vone][j_vtwo][k] = ans;
    return ans;
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        ll mp;
        cin>>mp;
        v1.push_back(mp);
    }
    for(int j=0;j<m;j++){
        ll op;
        cin>>op;
        v2.push_back(op);
    }
    memset(dp,-1,sizeof(dp));
    cout<<lcs_twist(0,0,n-1,m- 1,k)<<endl;;
    return 0;
}