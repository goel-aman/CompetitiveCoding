#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,q,k;
    cin>>n>>q>>k;
    ll a[n ];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    while(q--){
        ll left,right;
        cin>>left>>right;
        if(left == right){
            cout<<k - 1<<endl;
            continue;
        }
        ll least = 1;
        ll high = a[left];
        ll ans = 0;
        for(ll i = left - 1;i<=right - 1;i++){
            ll diff = high - least - 1;
            // cout<<"difference value is : "<<diff<<endl;
            ans+= diff;
            least = a[i];
            if(i + 1 == right - 1){
                high = k;
            }else{
                high = a[i + 2] - 1;
            }
            
        }
        cout<<ans<<endl;
    }
}