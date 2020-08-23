#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
 
int main(){
    ll t; cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n >= k){
            cout<<(n-k)%2<<endl;
        }else
        {
            cout<<k - n<<endl;
        }
    }
    return 0;
}