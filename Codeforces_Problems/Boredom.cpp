#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    map<ll,ll> um;
    for(ll i=0;i<n;i++){
        um[a[i]]++;
    }
    ll length = um.size();
    ll answer[length + 1];
    ll freq[length + 1];
    ll ans[length + 1];
    ans[0] = 0;
    answer[0] = 0;
    freq[0] = 0;
    ll i = 1;
    for(auto var : um){
        answer[i] = var.first;
        freq[i] = var.second;
        i++;
    }

    for(ll i=1;i<=length;i++){
        ll element = answer[i] - 1;
        ll j = i - 1;
        while(j > 0 && (element ==  answer[j]) ){
            j--;
        }

        ll temp = freq[i] * answer[i] + ans[j];
        ans[i] = max(temp,ans[i - 1]); 
    }
    cout<<ans[length]<<endl;
    return 0;    
}