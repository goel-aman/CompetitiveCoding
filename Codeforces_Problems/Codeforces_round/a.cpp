#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll findMoves(ll a,ll b){
    if( a == b){
        return 0;
    }

    ll diff = llabs(a - b);
    if(diff % 10 == 0){
        return diff / 10;
    }
    else{

        ll k = diff / 10;
        return (k+ 1);
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<findMoves(a,b)<<endl;
    }
    return 0;
}