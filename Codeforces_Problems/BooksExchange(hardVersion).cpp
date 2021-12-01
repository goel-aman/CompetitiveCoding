#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> arr,result;
ll value = 0;

void findValue(ll target,ll current){
    if(arr[current] != target){
        value++;
        findValue(target,arr[current]);
    }

    result[current] = value;
}

int main(){
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        arr.resize(n + 1);
        result.resize(n + 1,0);

        for(ll i=1;i<=n;i++){
            cin>>arr[i];
            result[i] = 0;
        }

        for(int i=1;i<=n;i++){
            if(result[i] == 0){
                value = 1;
                findValue(i,i);
            }
        }

        for(int i=1;i<=n;i++){
            cout<<result[i]<<" ";
        }

        cout<<endl;
    }
}