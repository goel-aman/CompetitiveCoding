#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll b[n];
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b, b + n);

    ll c[n];
    c[0] = b[0];
    for(ll i=1;i<n;i++){
        c[i] = c[i - 1] + b[i];
    }
    
    cout<<ans<<endl;
    return 0;
}