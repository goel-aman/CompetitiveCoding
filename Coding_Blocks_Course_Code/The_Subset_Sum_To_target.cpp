#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve(ll * arr,ll n,ll index,ll required_sum){
    if(required_sum < 0){
        return false;
    }
    if(index >= n && required_sum > 0){
        return false;
    }
    if(index >= n && required_sum == 0){
        return true;
    }

    bool ans = (solve(arr,n,index + 1, required_sum - arr[index]) || solve(arr,n,index + 1, required_sum) );
    return ans;
}

int main(){
    ll n,required_sum;

    cin>>n>>required_sum;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans = solve(arr,n,0,required_sum);
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}