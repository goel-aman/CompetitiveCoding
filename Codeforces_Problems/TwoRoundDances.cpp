#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fact[22];

void computeFact(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=21;i++){
        fact[i] = fact[i - 1] * i;
    }
    return ;
}

int main(){
    ll n;
    cin>>n;
    computeFact();
    if(n == 2){
        cout<<1<<endl;
        return 0;
    }

    ll nc2 = (fact[n]/(fact[n/2] * fact[n/2]));
    ll val = (n/2) - 1;
    ll value = (fact[val] * fact[val]);
    value = (value * nc2)/2;
    cout<<value<<endl;
    return 0;
}