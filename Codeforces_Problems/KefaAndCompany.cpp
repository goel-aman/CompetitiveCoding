#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.first  < b.first)
    {
        return true;
    }

    return false;
}

int main(){
    ll n,d;
    cin>>n>>d;
    
    // amount of money , friendshipFactor.
    vector<pair<ll,ll>> vec;
    ll maximumFriendship = 0;

    for(ll i=0;i<n;i++){
        ll amountOfMoney,friendshipFactor;
        cin>>amountOfMoney>>friendshipFactor;
        vec.push_back({amountOfMoney,friendshipFactor});
        maximumFriendship = max(maximumFriendship,friendshipFactor);
    }
    
    sort(vec.begin(),vec.end(),compare);

    ll sum = vec[0].second;
    maximumFriendship = max(maximumFriendship,sum);
    ll start = 0,end = 1;
    while(end < n){
        sum += vec[end].second;
        while((vec[end].first - vec[start].first) >= d){
            sum -= vec[start].second;
            start++;
        }

        maximumFriendship = max(maximumFriendship,sum);
        end++;
    }

    cout<<maximumFriendship<<endl;
    return 0;
}