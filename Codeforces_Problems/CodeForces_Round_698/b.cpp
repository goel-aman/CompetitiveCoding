#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll q,d;
        cin>>q>>d;
        ll a[q];
        for(ll i=0;i<q;i++){
            cin>>a[i];
            if(d == 1){
                cout<<"YES"<<endl;
                continue;
            }
            if(d%2 == 0){
                if(a[i]%d == 0 || a[i]%d == (d/2)){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
                continue;
            }

            if(a[i]%d != (d/2 + 1) || a[i]%d == 0){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}