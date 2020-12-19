#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll val = a + b + c;
        if(val < 9){
            cout<<"NO"<<endl;
            continue;

        }
        ll min_value = min(a,min(b,c));
        ll left_9 = val / 9;
        if(val %9 == 0 && min_value >= left_9 ){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}