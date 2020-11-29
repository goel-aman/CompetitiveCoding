#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n,m,r,c;
        cin>>n>>m>>r>>c;
        vector<vector<ll>> v;
        v.push_back({1,1});
        v.push_back({1,m});
        v.push_back({n,1});
        v.push_back({n,m});
        ll maxx = LONG_MIN;
        for(auto vv: v){
            // cout<<"value is : "<<vv[0]<<" "<<vv[1]<<endl;
            maxx = max(maxx,abs(vv[0] - r) + abs(vv[1] - c));
        }
        cout<<maxx<<endl;
    }
    return 0;
}