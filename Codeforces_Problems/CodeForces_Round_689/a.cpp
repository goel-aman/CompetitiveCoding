#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
#define mod 1000000007 // equal to 10^9 + 7
#define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string arr[] = {"a","b","c"};
        string output = "";
        for(int i=0;i<n;i++){
            output += arr[i%3];
        }
        cout<<output<<endl;
    }
    return 0;
}