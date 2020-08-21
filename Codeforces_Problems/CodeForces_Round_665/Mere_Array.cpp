#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll first, ll second){
    if(first == 0 || second == 0){
        return max(first,second);
    }

    ll x = max(first,second);
    ll y = min(first,second);
    return gcd(y,x%y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; 
    cin>>t;
    while(t--){
        ll n;cin>>n;
        ll arr[n];
        ll mini = LLONG_MAX;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] < mini){
                mini = arr[i];
            }
        }
        if(n == 1){
            cout<<"YES"<<endl;
            continue;
        }
        int flag = 1;
        for(ll i=0;i<n-1;i++){
            if(arr[i+1] >= arr[i]){
                continue;
            }
            else{
                flag = 0;
                break;
            }
        }

        if(flag == 1){
            cout<<"YES"<<endl;
            continue;
        }

        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                if(gcd(arr[j],arr[i]) == mini && arr[i] > arr[j]){
                    ll temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        int flag2 = 1;
        for(ll i=0;i<n - 1;i++){
            if(arr[i] <= arr[i+1]){
                continue;
            }
            else{
                flag2 = 0;
                break;
            }
        }
        if(flag2 == 0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}