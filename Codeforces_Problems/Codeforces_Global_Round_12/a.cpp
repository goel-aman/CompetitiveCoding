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
        string a;
        cin>>a;
        sort(a.begin(),a.end());
        cout<<a<<endl;
    }
    return 0;
}