#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        vector<ll> array;
        for(int i=0;i<n;i++){
            ll number;
            cin>>number;
            array.push_back(number);
        }

        ll ans = 0;
        sort(array.begin(),array.end());
        
        ll length = 0;
        for(ll j=n - 1;j>=0;j--){
            length++;
            if(array[j] * length >= x){
                ans++;
                length = 0;
            }
        }
        cout<<ans<<endl;
        // return 0;
    }
}