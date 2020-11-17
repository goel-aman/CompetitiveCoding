#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll a[n];
        ll b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=n-1;i>=0;i--){
            cin>>b[i];
        }
        int br = 0;
        for(ll i=0;i<n;i++)
        {
            ll sum = a[i] + b[i];
            if(sum > x){
                cout<<"No"<<endl;
                br = 1;
                break;
            }
        }
        if(br == 0){
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}