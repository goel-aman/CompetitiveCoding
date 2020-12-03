// #include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<climits>
#include<algorithm>

using namespace std;
#define ll long long int
#define prDouble(x,y) cout<< fixed << setprecision(y) << x

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n;
    cin>>n;
    ll heights[n];
    ll beauty[n];
    for(ll i=0;i<n;i++){
        cin>>heights[i];
    }
    for(ll i=0;i<n;i++){
        cin>>beauty[i];
    }
    ll answer[n];
    answer[0] = beauty[0];
    map<long long int,long long int> ma;
    ll maxx = LLONG_MIN;
    ma[heights[0]] = answer[0];
    if (answer[0] > maxx){
        maxx = answer[0];
    }

    for(ll i=1;i<n;i++){
        answer[i] = beauty[i];
        auto it = ma.lower_bound(heights[i] + 1);
        if(it != ma.begin()){
            it--;
            answer[i] += it->second;
        }
        ma[heights[i]] = answer[i];
        auto it2 = ma.upper_bound(heights[i]);
        while(it2 != ma.end() && it2->second <= answer[i] ){
            auto temp = it2;
            temp++;
            ma.erase(it2);
            it2 = temp;
        }
        if ( answer[i] > maxx){
            maxx = answer[i];
        }
    }
    cout<<maxx<<endl;
    return 0;
}