#include<bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map<string,int> um;

bool solve(ll i,ll j,ll k,ll &n,ll &m){
    if(i == n && j == m){
        if(k == 0){
            return true;
        }
        return false;
    }
    
    string value = to_string(i) + ";" + to_string(j) + ";" + to_string(k);


    if(um.count(value) > 0){
        return um[value];
    }

    if(i + 1 <= n && i + 1 >= 0){
        bool ans = solve(i + 1, j,k - j,n,m);
        if(ans){
            return um[value] = true;
        }    
    }

    if(j + 1 <= m && j + 1 >= 0){
        bool ans = solve(i,j + 1,k - i,n,m);
        if(ans){
            return um[value] = true;
        }
    }
    return um[value] = false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        um.clear();
        bool val = solve(1,1,k,n,m);
        if(val){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}