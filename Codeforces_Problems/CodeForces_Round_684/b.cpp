#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push
#define doublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<long long int> v;
        v.pb(0);
        for(ll i=0;i<n*k;i++){
            ll aa;
            cin>>aa;
            v.pb(aa);
        }
        ll ans = 0;
        ll start = (n * k) - (n / 2);
        for(ll i=0,j=n*k - (n/2);i<k;i++,j = (j -(n/2)) - 1){
            // cout<<v[j]<<endl;
            ans += v[j];
        }
        cout<<ans<<endl;
    }    
    return 0;
}
