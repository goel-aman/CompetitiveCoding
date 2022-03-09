#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> graph[100001];
ll ans = -1;

ll traverse(ll node,ll parent){
    ll count = 0;

    for(auto var : graph[node]){
        if(var != parent){
            count += traverse(var,node);
        }
    }

    ans += (count%2);
    return count + 1;
}

int main(){
    ll treesize;
    cin>>treesize;
    for(ll i=0;i<treesize - 1;i++){
        ll first,second;
        cin>>first>>second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    if(treesize%2 != 0){
        cout<<-1<<endl;
        return 0;
    }

    traverse(1,0);
    cout<<ans<<endl;
    return 0;
}