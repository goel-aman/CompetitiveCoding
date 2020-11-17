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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<max(a + b,c+d)<<endl;
    }
    return 0;
}