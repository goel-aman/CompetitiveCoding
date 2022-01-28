#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll w,h;
        cin>>w>>h;
        ll k;
        cin>>k;
        ll ans = INT_MIN;
        ll smallest = INT_MAX, largest = INT_MIN;
        ll difference = 0;
        for(ll i=0;i<k;i++){
            ll number;
            cin>>number;
            smallest = min(smallest,number);
            largest = max(largest,number);

            difference = max(abs(largest - smallest),difference);

            ans = max(ans,difference * h);
        }

        ll secondK;
        cin>>secondK;
        smallest = INT_MAX;
        largest = INT_MIN;
        difference = 0;
        for(ll i=0;i<secondK;i++){
            ll number;cin>>number;
            smallest = min(smallest,number);
            largest = max(largest,number);

            difference = max(abs(largest - smallest),difference);
            ans =max(ans,difference * h);            
        }

        ll thirdK;
        cin>>thirdK;
        smallest = INT_MAX;
        largest = INT_MIN;
        difference = 0;
        for(ll i=0;i<thirdK;i++){
            ll number;cin>>number;
            smallest = min(smallest,number);
            largest = max(largest,number);

            difference = max(abs(largest - smallest),difference);
            ans = max(ans,difference * w);
        }

        ll fourthK;
        cin>>fourthK;
        smallest = INT_MAX;
        largest = INT_MIN;
        difference = 0;
        for(ll i=0;i<fourthK;i++){
            ll number;
            cin>>number;
            smallest = min(smallest,number);
            largest = max(largest,number);

            difference = max(abs(largest - smallest),difference);
            ans = max(ans,difference * w);
        }       

        cout<<ans<<endl;       
    }
    return 0;
}