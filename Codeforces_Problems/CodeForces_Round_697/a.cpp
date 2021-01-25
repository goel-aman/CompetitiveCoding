#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        while(n%2 == 0){
            n = n / 2;
        }

        if(n == 1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}