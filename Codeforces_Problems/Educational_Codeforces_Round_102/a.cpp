#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define doubleprec(x,y) cout<<fixed<<setprecision(y)<<x


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll arr[n];
        ll count = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] <= d){
                count++;
            }
        }
        sort(arr,arr + n);
        ll sum = arr[0] + arr[1];
        if(sum <= d){
            cout<<"YES"<<endl;
            continue;
        }
        if(count == n){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}