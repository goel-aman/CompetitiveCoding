#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<long long int> vec = {a,b,c};
    sort(vec.begin(),vec.end());
    if(n%vec[0] == 0){
        // cout<<"hello"<<endl;
        cout<<n/vec[0]<<endl;
        return 0;
    }

    ll ans = INT_MIN;
    for(ll i=0;i<=n/vec[0];i++){
        ll left = n - (vec[0]*i);
        for(ll j=0;j<=left/vec[1];j++){
            ll left2 = left - (vec[1] * j);
            if(left2%vec[2] == 0){
                ll val =  i + j + (left2 / vec[2]);
                // cout<<"answer is : "<<ans<<endl;
                // cout<<"i is : "<<i<<endl;
                // cout<<"j is : "<<j<<endl;
                ans = max(ans,val); 
            }
        }
    }
    cout<<ans<<endl;
}