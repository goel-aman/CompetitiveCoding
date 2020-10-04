#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i]; 
        }
        ll total_pending = 0;
        ll ans = 0;
        ll i = 0;
        for(i=0;i<n;i++){
            total_pending += arr[i];
            if(total_pending < k){
                cout<<i+1<<endl;
                ans = 1;
                break;
            }
            total_pending -= k;
        }
        if(ans == 1){
            continue;
        }
        ll val = total_pending / k;
        i += val;
        cout<<i+1<<endl;
    }
    return 0;
}