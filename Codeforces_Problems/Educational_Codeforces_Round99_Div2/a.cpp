#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(string input){
    return input.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        string inp;
        cin>>inp;
        cout<<solve(inp)<<endl;
    }
    return 0;
}