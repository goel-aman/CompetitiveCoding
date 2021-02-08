#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll prime[1000005] = {0};
    unordered_map<long long int,bool> um;
    ll nn = 1000000;
    for(ll i=3;i<=nn;i+=2){
        prime[i] = 1;
    }

    for(ll i=3;i<=nn;i+=2){
        if(prime[i] == 1){
            um[(long long int) (i*i)] = true;
            for(ll j=i*i;j<=nn;j += i){
                prime[j] = 0;
            }
        }
    }
    um[4] = true;
    prime[1] = 0;
    prime[2] = 1;
    prime[0] = 0;
    // cout<<"hello"<<endl;
    for(ll m=0;m<n;m++){
        // cout<<"hello2"<<endl;
        if(um.count(a[m]) > 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }   
    return 0;
}