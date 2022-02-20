#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void traverse(ll node,vector<ll> &visited,ll &cost,unordered_map<ll,vector<ll>> &graph,vector<ll>& goldValue){
    visited[node] = 1;
    cost = min(cost,goldValue[node]);


    for(auto var : graph[node]){
        if(visited[var] == -1){
            visited[var] = 1;
            cost = min(cost,goldValue[var]);
            traverse(var,visited,cost,graph,goldValue);
        }
    }

    return ;
}

int main(){
    ll characters,friendPairs;
    cin>>characters>>friendPairs;
    vector<ll> goldValue;
    for(ll i=0;i<characters;i++){
        ll value;
        cin>>value;
        goldValue.push_back(value);
    }

    unordered_map<ll,vector<ll>> um;
    for(ll i=0;i<friendPairs;i++){
        ll first,second;
        cin>>first>>second;
        um[first - 1].push_back(second - 1);
        um[second - 1].push_back(first - 1);
    }
     
    vector<ll> visited(characters,-1);
    ll totalCost = 0;
    for(ll i=0;i<characters;i++){
        if(visited[i] > 0){
            continue;
        }

        ll cost = goldValue[i];
        traverse(i,visited,cost,um,goldValue);
        // cout<<"value of i is: "<<i<<" and cost is : "<<cost<<endl;
        totalCost += cost;
    }

    cout<<totalCost<<endl;
    return 0;
}