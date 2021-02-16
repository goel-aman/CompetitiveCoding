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
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans = 0;
        for(ll i=0;i<=n - 2;i++){
            if(max(a[i],a[i + 1]) <= 2 * min(a[i],a[i + 1])){
                continue;
            }
            
            while(! (max(a[i],a[i + 1]) <= 2* min(a[i],a[i + 1]) ) ){
                if(a[i] < a[i + 1]){
                    a[i] = 2 * a[i];
                }
                else{
                    if(a[i]%2 == 0){
                        a[i] /= 2;
                    }else{
                        a[i] /= 2;
                        a[i] += 1;
                    }
                    
                }
                ans++;
            } 
        }
        cout<<ans<<endl;
    }
}