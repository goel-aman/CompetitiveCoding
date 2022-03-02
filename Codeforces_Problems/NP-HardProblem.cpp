#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll traverse(vector<vector<ll>> &graph,vector<ll> &firstSection,vector<ll> &secondSection,ll node,vector<ll> &visited,ll color){
    visited[node] = color;
    if(color == 0){
        if(graph[node].size() > 0){
            firstSection.push_back(node);
        }
    }else{
        if(graph[node].size() > 0){
            secondSection.push_back(node);
        }
    }

    for(auto var : graph[node]){
        if(visited[var] == -1){
            if(traverse(graph,firstSection,secondSection,var,visited,!color)){
                return 1;
            }
        }else{
            if(visited[var] == color){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    ll vertices,edges;
    cin>>vertices>>edges;
    vector<ll> visited(vertices + 1,-1);
    // set<vector<ll>> ifExist;
    vector<vector<ll>> graph(vertices + 1);
    
    for(ll i=0;i<edges;i++){
        ll firstVertex,secondVertex;
        cin>>firstVertex>>secondVertex;

        graph[firstVertex].push_back(secondVertex);
        graph[secondVertex].push_back(firstVertex);
        // ifExist.insert({firstVertex,secondVertex});
    }
    ll value = 0;
    vector<ll> firstSection;
    vector<ll> secondSection;
    bool ans = true;
    for(ll i=1;i<=vertices;i++){
        if(visited[i] == -1){
            value = traverse(graph,firstSection,secondSection,i,visited,0);
            if(value){
                ans = false;
                break;
            }
        }
    }
    ll firstSectionLength = firstSection.size();
    ll secondSectionLength = secondSection.size();
    
    
    if(ans == false){
        cout<<-1<<endl;
        return 0;
    }

    cout<<firstSectionLength<<endl;
    for(auto var : firstSection){
        if(graph[var].size() > 0){
            cout<<var<<" ";
        }
    }
    cout<<endl;
    cout<<secondSectionLength<<endl;
    for(auto var : secondSection){
        if(graph[var].size() > 0){
            cout<<var<<" ";
        }
    }
    cout<<endl;
    return 0;
}