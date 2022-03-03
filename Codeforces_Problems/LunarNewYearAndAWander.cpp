#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll numberOfNodes;
    ll numberOfEdges;

    cin>>numberOfNodes>>numberOfEdges;
    unordered_map<ll,vector<ll>> graph;

    for(ll i=0;i<numberOfEdges;i++){
        ll firstVertex,secondVertex;
        cin>>firstVertex>>secondVertex;

        graph[firstVertex].push_back(secondVertex);
        graph[secondVertex].push_back(firstVertex);
    }
    vector<ll> visited(numberOfNodes + 1,-1);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    pq.push((ll) 1);
    visited[1] = true;
    while(!pq.empty()){
        ll value = pq.top();
        cout<<value<<" ";
        pq.pop();

        for(auto var : graph[value]){
            if(visited[var] == -1){
                pq.push(var);
                visited[var] = 1;
            }
        }
    }
    
    return 0;
}