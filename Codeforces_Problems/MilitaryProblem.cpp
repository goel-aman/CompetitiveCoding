#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> graph[200005];
vector<ll> traversal;
vector<ll> startingIndex(200005, 0);
vector<ll> commanderLength(200005,0);

ll traverse(ll node){
    startingIndex[node] = traversal.size();
    traversal.push_back(node);
    ll count = 1;
    for(auto var : graph[node]){
        ll tempAns = traverse(var);
        count += tempAns;
    }

    commanderLength[node] = count;
    return count;
}

int main(){
    ll numberOfOfficers;
    ll numberOfQueries;
    cin>>numberOfOfficers>>numberOfQueries;

    for(ll i=2;i<=numberOfOfficers;i++){
        ll supervisor;
        cin>>supervisor;

        graph[supervisor].push_back(i);
    }
    
    for(ll i=1;i<=numberOfOfficers;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    traverse(1);

    for(ll i=0;i<numberOfQueries;i++){
        ll commander,position;
        cin>>commander>>position;

        ll startingPosition = startingIndex[commander];
        if(position > commanderLength[commander]){
            cout<<-1<<endl;
        }else{
            cout<<traversal[startingPosition + position - 1]<<endl;
        }
    }

    return 0;
}