#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
const ll N = 2e5 + 5;
vector<ll> graph[N];
ll powFunc(ll n,ll k){
    ll ans = 1;
    while(k > 0){
        if(k&1){
            ans = (ans * n)%mod;
        }

        n = (n * n)%mod;
        k = k / 2;
    }
    return ans;
}

void traverse(vector<bool> &visited,ll node,ll &count){
    visited[node] = true;
    count++;

    for(auto &var : graph[node]){
        if(visited[var] == false){
            traverse(visited,var,count);
        }
    }

    return ;
}

int main(){
    ll n,k;
    cin>>n>>k;

    for(ll i=0;i<n - 1;i++){
        ll firstVertex,secondVertex,edgeColor;
        cin>>firstVertex>>secondVertex>>edgeColor;
        if(edgeColor == 0){
            graph[firstVertex].push_back(secondVertex);
            graph[secondVertex].push_back(firstVertex);
        }
    }

    ll value = powFunc(n,k);   
    ll sum = 0;
    vector<bool> visited(n + 1,false);
    for(ll i=1;i<=n;i++){
        if(visited[i] == false){
            ll count = 0;
            traverse(visited,i,count);
            value -= powFunc(count,k);
            value += mod;
            value %= mod;
        }
    }
    cout<<value<<endl;
    return 0;
}