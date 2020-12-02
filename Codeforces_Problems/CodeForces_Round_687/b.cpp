#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll n){
    if(n == 0){
        return 0;
    }
    ll i = 1;
    while( (i*(i+1)/2) < n ){
        i++;
    }

    ll day = ((i*(i + 1) )/ 2);
    if(n == day - 1){
        return i + 1;
    }
    return i;
    
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}