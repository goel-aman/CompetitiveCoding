#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        ll arr[n];
        ll arr2[n];
        ll mini = LLONG_MAX;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            arr2[i] = arr[i];
            if(arr[i] < mini){
                mini = arr[i];
            }
        }
        sort(arr,arr+n);
        int flag = 1;
        for(ll i=0;i<n;i++){
            if(arr[i] == arr2[i]){
                continue;
            }
            else{
                if(arr2[i]%mini != 0){
                    cout<<"NO"<<endl;
                    flag = 0;
                    break;
                }
            }
            
        }
        if(flag == 1){
            cout<<"YES"<<endl;
        }        
    }
    return 0;
}