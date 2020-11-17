#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

ll solve(ll val, ll prob){
    ll ans = INT_MIN;
    for(ll i = 1;i<=sqrt(val);i++){
        
        ll one,two;
        if(val % i == 0){
            one = val / i;
            two = i;
            if(one % prob != 0 && one >= ans){
                ans = one;
            }
            if(two % prob != 0 && two >= ans){
                ans = two;
            }
        }
        
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}