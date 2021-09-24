#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll> array;
    vector<ll> first;
    vector<ll> second;

    for(ll i=0;i<n;i++){
        ll number;
        cin>>number;
        first.push_back(number);
    }

    for(ll i=0;i<n;i++){
        ll number;
        cin>>number;
        second.push_back(number);
    }

    for(ll i=0;i<n;i++){
        ll difference = first[i] - second[i];
        array.push_back(difference);
    }
    sort(array.begin(),array.end());
    ll ans = 0;
    for(int i=0;i<n;i++){
        // cout<<array[i]<<" ";
        if(array[i] <=  0){
            auto it = lower_bound(array.begin(),array.end(),abs(array[i]) + 1);
            if(it == array.end()){
                continue;
            }
            ll index = it - array.begin();
            
            ans += n - index;
            continue;
        }

        ans += n - (i + 1); 
    }

    cout<<ans<<endl;
    return 0;
}