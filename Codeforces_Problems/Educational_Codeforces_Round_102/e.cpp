#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define doubleprec(x,y) cout<<fixed<<setprecision(y)<<x


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n == k){
            for(int i=1;i<=k;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }
        ll val = n - k;
        ll sum =(((n - k) * ( n - k + 1))/2);
        ll arr[k];
        for(ll i=0;i<k;i++){
            arr[i] = i + 1;
        }
        ll kfact = 1;
        for(ll i=1;i<=k;i++){
            kfact *= i;
        }
        if(sum > kfact){
            for(ll i=k;i>=1;i--){
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }
        else{
            for(ll i=0;i<sum;i++){
                next_permutation(arr, arr + k);
            }
            for(ll i=0;i<k;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}