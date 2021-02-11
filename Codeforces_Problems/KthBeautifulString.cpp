#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<char> v(n,'a');
        ll i = n - 2;
        while(k > n - i - 1){
            k -= (n - i - 1);
            i = i - 1;
        }
        // cout<<i<<endl;
        v[i] = 'b';
        v[n - k] = 'b';
        for(int i=0;i<n;i++){
            cout<<v[i];
        }
        cout<<endl;
    }
}