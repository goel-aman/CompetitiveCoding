#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll prev;
        cin>>prev;
        prev = abs(prev);
        ll sum = 0; 
        for(ll i=0;i<n - 1;i++){
            ll current;
            cin>>current;
            current = abs(current);
            sum += (prev - current);
        }
        cout<<abs(sum)<<endl;
    }
    return 0;
}