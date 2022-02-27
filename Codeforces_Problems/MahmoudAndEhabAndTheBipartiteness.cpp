#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void traverse(ll node,ll value,unordered_map<ll,vector<ll>> &graph,vector<int> &visited,ll &zeroCount,ll &oneCount){
    if(value == 0){
        zeroCount++;
    }
    else{
        oneCount++;
    }

    visited[node] = 1;

    for(auto var: graph[node]){
        if(visited[var] == -1){
            traverse(var,!value,graph,visited,zeroCount,oneCount);
        }
    }
    return ;
}   

int main(){
    ll numberOfNodes;
    cin>>numberOfNodes;

    unordered_map<ll,vector<ll>> graph;
    for(ll i=0;i<numberOfNodes - 1;i++){
        ll firstNumber,secondNumber;
        cin>>firstNumber>>secondNumber;

        graph[firstNumber].push_back(secondNumber);
        graph[secondNumber].push_back(firstNumber);
    }
    
    
    ll zeroCount = 0;
    ll oneCount = 0;
    vector<int> visited(numberOfNodes + 1,-1);

    traverse(1,0,graph,visited,zeroCount,oneCount);
    ll ans = (zeroCount * oneCount) - (numberOfNodes - 1);
    cout<<ans<<endl;
    return 0;
}



