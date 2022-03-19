#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> graph[200005];
ll colors[200005];

void traverse(ll currentNode,ll parentNode,ll &result){    
    ll c = 1;

    for(auto var : graph[currentNode]){
        if(var == parentNode){
            continue;
        }

        while(c == colors[currentNode] || c == colors[parentNode]){
            c++;
        }

        
        result = max(result,c);
        colors[var] = c;
        c++;
        traverse(var,currentNode,result);
    }

    return ;
}


int main(){
    ll numberOfSquares;
    cin>>numberOfSquares;

    for(ll i=1;i<=numberOfSquares - 1;i++){
        ll firstNode,secondNode;
        cin>>firstNode>>secondNode;

        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }

    ll result = 1;
    colors[1] = 1;
    traverse(1,-1,result);
    cout<<result<<endl;
    for(ll i=1;i<=numberOfSquares;i++){
        cout<<colors[i]<<" ";
    }
    cout<<endl;
    return 0;
}