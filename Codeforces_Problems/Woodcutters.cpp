#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll sizee;

ll solve(vector<pair<ll,ll>> &vec,ll index,ll prev,unordered_map<string,ll> &um){
    if(index == sizee){
        return 0;
    }   

    string dp = to_string(index) + ";" + to_string(prev);
    if(um.count(dp)){
        return um[dp];
    }
    
    ll value = 0;
    // lets try to fall backward
    ll backwardDistance = vec[index].first - prev;
    if(backwardDistance >= vec[index].second + 1){
        value = max(value,solve(vec,index + 1,vec[index].first,um) + 1);
    }

    // lets not fall it
    value = max(value,solve(vec,index + 1,vec[index].first,um));

    // lets try to fall it in forward Direction.
    ll forwardDistance = vec[index + 1].first - vec[index].first;
    if(forwardDistance >= vec[index].second + 1){
        value = max(value,solve(vec,index + 1,vec[index].first + vec[index].second,um) + 1);
    }

    return um[dp] = value;
}

int main(){
    ll n;
    cin>>n;
    sizee = n;
    vector<pair<ll,ll>> vec;
    while(n--){
        ll coordinate,height;
        cin>>coordinate>>height;
        vec.push_back({coordinate,height});
    }
    
    if(sizee <= 2){
        cout<<sizee<<endl;
        return 0;
    }

    ll ans = 0;
    ans += 2;
    sizee -= 1;
    unordered_map<string,ll> um;
    ans += solve(vec,1,vec[0].first,um);
    cout<<ans<<endl;
    return 0;
}