#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll e,n;
    cin>>e>>n;
    ll ans = min(e,min(n,(e + n)/ 3));
    cout<<ans<<endl;
    return 0;
}