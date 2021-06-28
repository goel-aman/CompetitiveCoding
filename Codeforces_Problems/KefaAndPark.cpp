#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


ll leafReachable(unordered_map<int,vector<int>>& um,int root,int m,ll* a,int consecutive,vector<int>& visited){
    if(visited[root] == 1){
        return 0;
    }

    visited[root] = 1;
    if(a[root] == 1){
        consecutive++;
    }

    if(consecutive > m){
        return 0;
    }
    int f = 0;
    ll answer = 0;
    for(auto var : um[root]){
        if(visited[var] == -1){
            f = 1;
            if(a[var] == 0){
                answer += leafReachable(um,var,m,a,0,visited);
            }else{
                answer += leafReachable(um,var,m,a,consecutive,visited);
            }
        }
    }

    if(f == 0){
        return 1;
    }
    return answer;
}


int main(){
    unordered_map<int,vector<int>> um;
    ll n,m;
    cin>>n>>m;
    ll a[n + 1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n - 1;i++){
        ll x,y;
        cin>>x>>y;
        um[x].push_back(y);
        um[y].push_back(x);
    }

    vector<int> visited(n + 1,-1);

    cout<<leafReachable(um,1,m,a,0,visited)<<endl;
    return 0;
}