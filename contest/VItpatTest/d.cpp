#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,b;
        cin>>n>>b;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll maximum = 0;
        ll sum = 0;
        ll i=0,j = 0;
        while(j < n && i < n){
            if(sum + a[j] <= b){
                sum += a[j];
                j++;
                maximum = max(sum,maximum);
            }
            else{
                sum -= a[i];
                i++;
                if(sum < 0){
                    sum = 0;
                    j = i;
                }
            }
        }
        cout<<maximum<<endl;
    }
}