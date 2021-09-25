#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll sLength = s.length();
        // {number of zeros,number of ones};
        vector<pair<ll,ll>> prefix;
        vector<pair<ll,ll>> suffix;
        int oneCount = 0;
        int zeroCount = 0;
        for(ll i=0;i<sLength;i++){
            if(s[i] == '1'){
                oneCount++;
            }
            else{
                zeroCount++;
            }

            prefix.push_back({zeroCount,oneCount});
        }

        ll ans = INT_MAX;
        oneCount = 0;
        zeroCount = 0;
        for(ll i=sLength - 1;i>=0;i--){
            if(s[i] == '1'){
                oneCount++;
            }
            else{
                zeroCount++;
            }

            suffix.push_back({zeroCount,oneCount});            
        }
        reverse(suffix.begin(),suffix.end());

        for(ll i=0;i<sLength;i++){
            ll requiredStep = prefix[i].first;
            ll front = 0;
            if(i + 1 < sLength){
                front = suffix[i + 1].second;
            }
            ll requiredStep2 = prefix[i].second;
            ll frontt = 0;
            if(i + 1 < sLength){
                frontt = suffix[i + 1].first;
            }
            ans = min(ans,requiredStep + front);
            ans = min(ans,frontt + requiredStep2);
        }

        for(ll i=sLength - 1;i>=0;i--){
            ll requiredStep = suffix[i].first;
            ll back = 0;
            if(i - 1 >= 0) {
                back = prefix[i - 1].second;
            }

            ll requiredStep2 = suffix[i].second;
            ll backk = 0;
            if(i - 1 >= 0){
                backk = prefix[i - 1].first;
            }
            ans = min(ans,back + requiredStep);
            ans = min(ans,backk + requiredStep2);
        }

        if(sLength == zeroCount || sLength == oneCount){
            ans = 0;
        }
        cout<<ans<<endl;
    }
}