#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main(){
    ll n;
    cin>>n;
    ll arr[n][3];
    for(ll i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    ll answer[n][3];
    answer[0][0] = arr[0][0];
    answer[0][1] = arr[0][1];
    answer[0][2] = arr[0][2];
    for(ll i=1;i<n;i++){
        for(ll j=0;j<3;j++){
            answer[i][j] = arr[i][j] + max(answer[i-1][(j+1)%3],answer[i-1][(j+2)%3]);
        }
    }
    ll answerr = max(answer[n-1][0],max(answer[n-1][1],answer[n-1][2]));
    cout<<answerr<<endl;
    return 0;
}