#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll p[n];
        ll sum = 0;
        for(ll i=0;i<n;i++){
            cin>>p[i];
        }
        sum = p[0];
        ll ans = 0;
        for(ll i=1;i<n;i++){
            ll rs = (100 * p[i]) / k;
            if((100* p[i])%k){
                rs++;
            }
            ans = max(ans,rs - sum);
            sum += p[i];
        }
        cout<<ans<<endl;
    }
}