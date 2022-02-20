#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void traverse(unordered_map<ll,vector<ll>> &graph,vector<ll> &components,vector<ll> &visited,ll node){
    visited[node] = 1;
    components.push_back(node);
    for(auto var : graph[node]){
        if(visited[var] == 0){
            traverse(graph,components,visited,var);
        }
    }
    return ;
}

int main(){
    ll numberOfVertices,numberOfEdges;
    cin>>numberOfVertices>>numberOfEdges;
    unordered_map<ll,vector<ll>> graph;

    for(ll i=0;i<numberOfEdges;i++){
        ll first,second;
        cin>>first>>second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    ll numberOfCyclicComponents = 0;
    vector<ll> visited(numberOfVertices + 1,0);
    vector<ll> components;
    for(ll i=1;i<=numberOfVertices;i++){
       components.clear();
        if(visited[i] == 0){
            traverse(graph,components,visited,i);
            bool isCycle = true;
            if(components.size() > 2){
                for(auto var : components){
                    if(graph[var].size() != 2){
                        isCycle = false;
                    }
                }
                if(isCycle == true){
                    numberOfCyclicComponents++;
                }
            }
        }

    }

    cout<<numberOfCyclicComponents<<endl;
    return 0;
}