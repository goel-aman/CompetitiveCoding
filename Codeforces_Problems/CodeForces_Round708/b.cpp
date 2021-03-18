#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll a[n];
        unordered_map<ll,ll> um;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            um[a[i] % m]++;
        }

        ll ans = 0;
        for(ll i=0;i<m;i++){
            if(um.count(i) > 0){
                if(um[i] == 0){
                    continue;
                }
                if(i == 0 ){
                    ans++;
                    um[i] = 0;
                    // cout<<"value after comp1letion of "<< i<<"th is : "<<ans<<endl;
                    continue;
                }
                if(i == m/2 && m%2 == 0){
                    ans++;
                    um[i] = 0;
                    // cout<<"value after completion of "<< i<<"th is : "<<ans<<endl;
                    continue;
                }
                
                int diff = abs(um[i] - um[m - i]);
                if(diff == 0 || diff == 1) {
                    ans++;
                    um[i] = 0;
                    um[m - i] = 0;
                    // cout<<"Value of um[i] is : "<<um[i]<<" and value of um[i - 1] is : "<<um[i - 1]<<endl;
                    // cout<<"value after completion of "<< i<<"th is : "<<ans<<endl;
                    continue;
                }

                ll mini = min(um[i],um[m - i]);
                if(um[i] < um[m - i]){
                    um[m - i] -= um[i] - 1;
                    um[i] = 0;
                    ans++;
                    // cout<<"value after completion of "<< i<<"th is : "<<ans<<endl;
                    continue;
                }

                if(um[i] > um[m - i]){
                    um[i] = um[i] -  um[m - i] - 1;
                    um[m - i] = 0;
                    ans++;
                    ans += um[i];
                    um[i] = 0;
                    // cout<<"value after completion of "<< i<<"th is : "<<ans<<endl;
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}