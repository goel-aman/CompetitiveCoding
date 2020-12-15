#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
#define mod 1000000007 // equal to 10^9 + 7
#define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl

ll solve(vector<ll> arr){
    int length = arr.size();
    if(length == 0 || length == 1){
        return 0;
    }
    bool status = true;
    ll val = arr[0];
    for(ll i=1;i<length;i++){
        if(val != arr[i]){
            status = false;
            break;
        }
    }

    if(status){
        return 0;
    }
    ll ans = 0;
    for(ll i=0;i<length;i++){
        if(i == 0){
            vector<ll> newv;
            for(ll j=i + 1;j<length;j++){
                if(i == 1){
                    newv.push_back(arr[i] + arr[i - 1]);
                    continue;
                }
                newv.push_back(arr[i]);
            }
            ans = max(ans,1 + solve(newv));
            continue;
        }

        

    }

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> vv;
        string s;
        for(ll i=0;i<n;i++){
            ll num;
            cin>>num;
            vv.push_back(num);
        }
        solve(vv);
    }
    return 0;
}