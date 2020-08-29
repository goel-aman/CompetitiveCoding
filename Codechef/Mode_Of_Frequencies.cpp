#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        unordered_map<long long int,long long int> um;
        unordered_map<long long int,long long int> umm;
        vector<long long int> v;
  
        for(ll i=0;i<n;i++){
            cin>>a[i];
            um[a[i]]++;
        }
        for(auto x: um){
           umm[x.second]++;
        }
        ll max = 0;
        for(auto x: umm){
            // cout<<x.first<<" "<<x.second<<" "<<endl;
            if(x.second > max){
                max = x.second;
                v.clear();
                v.push_back(x.first);
                continue;
            }
            if(x.second == max){
                v.push_back(x.first);
                continue;
            }
        }
        // cout<<"value of max is : " <<max<<endl;
        // cout<<"over"<<endl;
        // for(auto y: v){
        //     cout<<y<<" ";
        // }
        // cout<<endl;
        ll ans = LLONG_MAX;
        for(ll i=0;i<v.size();i++){
            if(v[i] < ans){
                ans = v[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}