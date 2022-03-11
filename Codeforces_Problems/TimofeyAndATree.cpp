#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> graph[100001];
vector<ll> color(100001,-1);

bool dfs(ll node,unordered_set<ll> &colorCount,ll parent){
    colorCount.insert(color[node]);
    if(colorCount.size() > 1){
        return false;
    }

    for(auto var : graph[node]){
        if(var != parent){
            bool val = dfs(var,colorCount,node);
            if(val == false){
                return false;
            }
        }
    }

    return true;
}

bool traverse(ll node){
    for(auto var: graph[node]){
        unordered_set<ll> colorCount;
        bool ans = dfs(var,colorCount,node);
        if(ans == false){
            return false;
        }
    }
    return true;
}   

int main() {
    ll numberOfVertices;
    cin>>numberOfVertices;
    vector<vector<ll>> edges;
    for(ll i=0;i<numberOfVertices - 1;i++){
        ll firstVertex, secondVertex;
        cin>>firstVertex>>secondVertex;
        edges.push_back({firstVertex,secondVertex});
        graph[firstVertex].push_back(secondVertex);
        graph[secondVertex].push_back(firstVertex);
    }

    for(ll i=1;i<=numberOfVertices;i++){
        ll colorNumber;
        cin>>colorNumber;
        color[i] = colorNumber;
    }    
    ll ans = -1;
    bool entered = false;
    for(ll i=0;i<numberOfVertices - 1;i++){
        if(color[edges[i][0]] != color[edges[i][1]]){
            bool first = traverse(edges[i][0]);

            bool second = traverse(edges[i][1]);
            if(first == false && second == false){
                ans = -2;
                break;
            }
            if(first){
                ans = edges[i][0];
                break;
            }

            if(second){
                ans = edges[i][1];
                break;
            }
        }
    }   

    if(ans == -2){
        cout<<"NO"<<endl;
    }else if (ans == -1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}