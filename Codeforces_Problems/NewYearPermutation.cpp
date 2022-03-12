#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void traverse(vector<ll> &chainIndex,vector<ll> &elementValue,ll node,vector<ll> &visited,vector<ll> &permutations,unordered_map<ll,vector<ll>> &graph){
    visited[node] = true;

    chainIndex.push_back(node);
    elementValue.push_back(permutations[node]);

    for(auto var : graph[node]){
        if(visited[var] == -1){
            traverse(chainIndex,elementValue,var,visited,permutations,graph);
        }
    }
    return ;
}

int main(){
    ll sizeOfPermutation;
    cin>>sizeOfPermutation;

    vector<ll> permutations;
    for(ll i=0;i<sizeOfPermutation;i++){
        ll value;
        cin>>value;
        permutations.push_back(value);
    }

    unordered_map<ll,vector<ll>> graph;
    for(ll i=0;i<sizeOfPermutation;i++){
        string val;
        cin>>val;
        for(ll j=0;j<sizeOfPermutation;j++){
            if(val[j] == '1'){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    vector<ll> visited(sizeOfPermutation, -1);
    for(ll i=0;i<sizeOfPermutation;i++){
        if(visited[i] == -1){
            vector<ll> chainIndex;
            vector<ll> elementValue;
            traverse(chainIndex,elementValue,i,visited,permutations,graph);
            sort(elementValue.begin(),elementValue.end());
            sort(chainIndex.begin(),chainIndex.end());
            for(ll j=0;j<elementValue.size();j++){
                permutations[chainIndex[j]] = elementValue[j];
            }
        }
    }
    for(auto var : permutations){
        cout<<var<<" ";
    }
    cout<<endl;

    return 0;
}