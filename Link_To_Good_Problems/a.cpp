#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll totalBits = 0,temp = n;
        while(temp != 0){
            totalBits += 1;
            temp = (temp >> 1);
        }
        // cout<<totalBits<<endl;
        ll answer = (1 << (totalBits - 1) ) - 1;
        cout<<answer<<endl;
    }
}