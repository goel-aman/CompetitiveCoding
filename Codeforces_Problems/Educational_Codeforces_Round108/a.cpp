#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll r,b,d;
        cin>>r>>b>>d;
        if(d == 0){
            if(r == b){
                cout<<"YES"<<endl;
                continue;
            }else{
                cout<<"NO"<<endl;
                continue;
            }
        }

        ll morballs = max(r,b);
        ll lessballs = min(r,b);

        ll value = morballs - ((d + 1) * lessballs);
        if(value <= 0){
            cout<<"YES"<<endl;
            continue;
        }else{
            cout<<"NO"<<endl;
            continue;
        }
    }
    return 0;
}