#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        vector<ll> num;
        for(ll i=0;i<n;i++){
            ll number;
            cin>>number;
            num.push_back(number);
        }
        ll ans = 0;

        sort(num.begin(),num.end());
        
        if(num[0] > r){
            cout<<0<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            if(num[i] > r){
                break;
            }

            int maxNumber = r - num[i];
            int minNumber = (num[i] >= l) ? 0 : l - num[i];

            auto first = lower_bound(num.begin() + i + 1,num.end(),minNumber);
            auto second = upper_bound(num.begin() + i + 1,num.end(),maxNumber);

            int difference = second - first;
            ans += difference;
        }
        cout<<ans<<endl;
    }
}