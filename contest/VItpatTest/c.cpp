#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(k == 1){
            cout<<0<<endl;
            continue;
        }
        sort(a,a+n);
        ll mini = INT_MAX;
        for(int i=0;i<=n-k;i++){
            ll diff = a[i + k - 1] - a[i];
            mini = min(diff,mini);
        }
        
        cout<<mini<<endl;
    }
}