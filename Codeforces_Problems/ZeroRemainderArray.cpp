#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// Zero Remainder Array

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans = 0;
        ll done = 0;
        ll maxValue = 0,maxFrequency = INT_MIN;
        map<ll,ll> um;
        for(ll i=0;i<n;i++){
            ll number;cin>>number;

            if(number%k != 0){
                ll required = (k) - (number%k);
                um[required]++;
                if(um[required] > maxFrequency){
                    maxFrequency = um[required];
                    maxValue = required;
                }

                if(um[required] == maxFrequency){
                    maxValue = max(maxValue,required);
                }
            }
        }

        if(um.size() == 0){
            cout<<0<<endl;
            continue;
        }

        ans = 1;
        ans += maxValue;
        ans += (k * (maxFrequency - 1)); 
        cout<<ans<<endl;
    }
}

