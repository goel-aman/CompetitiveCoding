#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> graph[100005];
vector<ll> whiteNodes(100005,0);
vector<ll> ansNodes(100005,0);
vector<ll> ans;
void traverse(ll currentNode,ll parentNode){
    ll value = whiteNodes[currentNode];
    for(auto var : graph[currentNode]){
        if(var != parentNode){
            traverse(var,currentNode);
            value += ansNodes[var];
        }
    }

    ansNodes[currentNode] = value;
    if(ansNodes[currentNode] == 1){
        ans.push_back(currentNode);
    }
}

int main(){
    ll numberOfDistricts;
    cin>>numberOfDistricts;

    for(ll i=0;i<numberOfDistricts - 1;i++){
        ll firstVertex,secondVertex,broken;
        cin>>firstVertex>>secondVertex>>broken;
        graph[firstVertex].push_back({secondVertex});
        graph[secondVertex].push_back({firstVertex});
        
        if(broken == 2){
            whiteNodes[firstVertex] = 1;
            whiteNodes[secondVertex] = 1;
        }
    }

    traverse(1,-1);

    cout<<ans.size()<<endl;
    for(auto var: ans){
        cout<<var<<" ";
    }
    cout<<endl;
    return 0;
}