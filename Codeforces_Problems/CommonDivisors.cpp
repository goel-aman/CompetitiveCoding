#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a,ll b){
    if(a == 0)
    {
        return b;
    }

    return gcd(b%a,a);
}

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 0;
    ll result = a[0];
    for(int i=1;i<n;i++){
        result = gcd(result,a[i]);
        if(result == 1){
            ans = 1;
            cout<<1<<endl;
            break;
        }
    }
    set<long long int> finalans;
    if(ans != 1){
        for(ll i=1;i<=sqrt(result);i++){
            if(result % i == 0){
                finalans.insert(i);
                finalans.insert(result / i);
            }
        }
        cout<<finalans.size()<<endl;
    }
    return 0;
}