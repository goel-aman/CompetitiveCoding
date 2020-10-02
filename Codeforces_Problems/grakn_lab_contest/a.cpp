#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[3][n];
        for(ll i=0;i<3;i++){
            for(ll j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        vector<ll> answer;
        ll prev = -1;
        ll last = -1;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<3;j++){
                if(arr[j][i] != prev){
                    if(i == 0){
                        last = arr[j][i];
                    }
                    if(i == n-1 && arr[j][i] == last){
                        continue;
                    }
                    answer.push_back(arr[j][i]);
                    prev = arr[j][i];
                    break;
                }
            }
        }
        for(auto x: answer){
            cout<<x<<" ";
        }
        cout<<endl;
    }
return 0;
}