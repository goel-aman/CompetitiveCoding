#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n%2 == 0)
        {
            if(k%n == 0){
                cout<<n<<endl;
            }else{
                cout<<k%n<<endl;
            }
            continue;
        }

        ll ans = n / 2;
        if(k <= ans){
            cout<<k<<endl;
            continue;
        }

        ll var = k - ans;
        ll factor = n / 2;
        if(var%factor == 0){
            ans += var + (var / factor);
        }
        else{
            ans += var + (var / factor) + 1;
        }
        if(ans%n == 0){
            cout<<n<<endl;
            continue;
        }
        cout<<ans%n<<endl;
    
    }
    return 0;
}