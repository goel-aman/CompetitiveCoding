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
        ll maxx = 1;
        ll ans = 1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        for(ll i=1;i<n;i++){
            if(a[i] == a[i - 1]){
                ans++;
                maxx= max(ans,maxx); 
            }
            else{
                ans = 1;
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}