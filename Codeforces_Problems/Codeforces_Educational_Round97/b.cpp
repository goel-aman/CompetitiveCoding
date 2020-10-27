#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x


ll solve(string s,ll n){
    if(n == 0){
        return 0;
    }

    if(s == "01" || s == "10"){
        return 0;
    }


    ll max_consecutive = 1;
    char prev = s[0];
    ll var = 1;
    for(ll i=1;i<n;i++){
        if(prev == s[i]){
            var++;
            if(var > max_consecutive){
                max_consecutive = var;
            }
        }
        else{
            var = 1;
            prev = s[i];
        }
    }
    return max_consecutive - 1;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s,n)<<endl;
    }
    return 0;
}