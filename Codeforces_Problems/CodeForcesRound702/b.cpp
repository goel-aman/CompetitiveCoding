#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        ll c0 = 0;
        ll c1 = 0;
        ll c2 = 0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%3 == 0){
                c0++;
            }

            if(a[i]%3 == 1){
                c1++;
            }

            if(a[i]%3 == 2){
                c2++;
            }
        }
        ll target = n / 3;
        ll ans = 0;
        if(c0 != target){
            if(c0 > target){
                ans += (c0 - target);
                c1 += (c0 - target);
            }else{
                ans += (target - c0);
                c2 -= (target - c0);
            }
        }

        if(c1 != target){
            if(c1 > target){
                ans += (c1 - target);
                c2 += (c1 - target);
            }else{
                ans += 2 * (target - c1);
                c2 -= (target - c1);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}