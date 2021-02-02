#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll a[k];
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        sort(a, a + k);
        // cout<<"a k - 1 is : "<<a[k - 1]<<endl;
        // cout<<"a0 is : "<<a[0]<<endl;
        ll ans = a[k - 2] - a[0];
        cout<<ans<<endl;
    }
}