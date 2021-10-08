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
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll primeFactors[] = {2,3,5,7,11,13,17,19,23,29,31};
        ll ans[n];
        for(ll i=0;i<n;i++){
            ans[i] = -1;
        }

        int color = 1;
        for(int j=0;j<11;j++){
            bool got = false;
            for(int i=0;i<n;i++){
                if(ans[i] != -1){
                    continue;
                }

                if(a[i]%primeFactors[j] != 0){
                    continue;
                }

                got = 1;
                ans[i] = color;
            }
            if(got){
                color++;
            }
        }
        cout<<color - 1<<endl;
        for(ll i=0;i<n;i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
}