#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        if(r < 2*l && l > r/2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}