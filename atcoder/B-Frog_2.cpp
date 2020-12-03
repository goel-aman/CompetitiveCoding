#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n,k;
    cin>>n>>k;
    ll input_array[n];
    ll answer_array[n];
    for(ll i=0;i<n;i++){
        cin>>input_array[i];
    }
    answer_array[0] = 0;
    for(ll i=1;i<n;i++){
        ll mini = LLONG_MAX;
        for(ll j=1;j<=k;j++){
            if(i - j >= 0 ){
                ll diff = abs(input_array[i] - input_array[i-j]) +answer_array[i-j];
                if(diff < mini){
                    mini = diff;
                } 
            }
        }
        answer_array[i] = mini;
    }
    cout<<answer_array[n-1]<<endl;
    return 0;
}