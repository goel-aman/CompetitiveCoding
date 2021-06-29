#include<bits/stdc++.h>
using namespace std;

// Product of Three Numbers

#define ll long long int

int main(){
    ll t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        unordered_map<ll,ll> um;

        while(n%2 == 0){
            um[2]++;
            n = n /2;
        }

        for(ll i=3;i<=sqrt(n);i+=2){
            while(n%i == 0){
                // cout<<"i is: "<<i<<endl;
                um[i]++;
                n = n / i;
            }
        }

        if(n > 2){
            // cout<<"n is : "<<n<<endl;
            um[n]++;
        }

        if(um.size() == 1){
            ll sum = 0;
            ll num;
            for(auto var : um){
                sum += var.second;
                num = var.first;
            }
            if(sum >= 6){
                cout<<"YES"<<endl;
                ll val = pow(num,sum - 3);
                cout<<num<<" "<<num * num<<" "<<val<<endl;
                continue;
            }else{
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(um.size() == 2){
            ll sum = 0;
            vector<pair<ll,ll>> temp;
            for(auto var : um){
                sum += var.second;
                temp.push_back({var.first,var.second});
            }
            if(sum < 4){
                cout<<"NO"<<endl;
                continue;
            }

            cout<<"YES"<<endl;
            ll value = pow(temp[0].first,temp[0].second - 1) * pow(temp[1].first,temp[1].second - 1);
            cout<<temp[0].first<<" "<<temp[1].first<<" "<<value<<endl;
            continue;
        }

        vector<pair<ll,ll>> temp;
        ll vall = 1;
        for(auto var : um)
        {
            if(var.second == 1){
                vall = vall * var.first;
            }else{
                vall = vall * (ll) pow(var.first,var.second);
            }
            temp.push_back({var.first,var.second});
        }

        cout<<"YES"<<endl;
        ll ans = (vall/(temp[0].first * temp[1].first));
        
        cout<<temp[0].first<<" "<<temp[1].first<<" "<<ans<<endl;
        continue;

    }
    return 0;
}