#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    while(n--){
        ll t;
        cin>>t;
        ll ans = 0;
        while(t > 0){
            ans += t;
            t = t/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}