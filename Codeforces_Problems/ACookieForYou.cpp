#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll v,c;
        cin>>v>>c;
        ll n,m;
        cin>>n>>m;
        if(v + c < n + m){
            cout<<"NO"<<endl;
            continue;
        }

        
        ll mini = min(v,c);
        ll maxi = max(v,c);
        if(mini >= m){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}