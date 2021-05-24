#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        ll mini = INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mini = min(a[i],mini);
        }
        ll count = 0;
        for(int i=0;i<n;i++){
            if(a[i] == mini){
                count++;
            }
        }

        cout<<n - count<<endl;
    }
}