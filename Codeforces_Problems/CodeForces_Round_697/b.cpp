#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int gotanswer = 0;
        for(ll i=0;i<=(n / 2020);i++){
            if( (n - (2020 * i))%2021 == 0){
                gotanswer = 1;
                break;
            }
        }
        if(gotanswer){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}