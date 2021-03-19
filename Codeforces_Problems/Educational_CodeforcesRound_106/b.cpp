#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k1,k2;
        cin>>n>>k1>>k2;
        ll w,b;
        cin>>w>>b;
        ll totalwhite = min(k1,k2);
        ll diff = max(k1,k2) - totalwhite;
        if(diff > 0){
            if(diff%2 == 0){
                totalwhite += diff/2;
            }
            else{
                totalwhite = totalwhite + (diff - 1) / 2;
            }
        }
        ll n1 = n - k1;
        ll n2 = n - k2;
        ll totalblack = min(n1,n2);
        ll df = max(n1,n2) - totalblack;
        if(df > 0){
            if(df%2 == 0){
                totalblack += df / 2;
            }
            else{
                totalblack = totalblack + ((df - 1) / 2);
            }
        }
        if(w <= totalwhite && b <= totalblack){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}