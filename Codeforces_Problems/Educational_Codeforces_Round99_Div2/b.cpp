#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll current_position,ll destination){
    if(current_position == destination)
    {
        return 0;
    }

    ll k = 1;
    queue<ll> q;
    ll level = 0;
    q.push(current_position);
    q.push(LONG_LONG_MIN);
    while(!q.empty()){
        ll val = q.front();
        if(val == destination){
            return level;
        }
        if(val == LONG_LONG_MIN){
            q.pop();
            level++;
            k++;
            q.push(LONG_LONG_MIN);
            continue;
        }
        q.pop();
        q.push(val - 1);
        q.push(val  + k);
    }
    return -1;
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll x;cin>>x;
        cout<<solve(0,x)<<endl;
    }
    return 0;
}
