#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--){  
        ll n,k,x,y;
        cin>>n>>k>>x>>y;
        k = k % n;
        if( y == x){
            cout<<"YES"<<endl;
            continue;
        }
        unordered_map<long long int,bool> um;
        um[x] = true;
        ll p = ( x + k ) % n;
        int ans = 0;
        while( !(um.count(p) > 0)){
            if( y == p){
                cout<<"YES"<<endl;
                ans = 1;
                break;
            }
            um[p] = true;
            p = ( p + k ) % n;
        }
        if(ans == 1){
            // cout<<"YES"<<endl;
            continue;
        }
        if(ans == 0){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}