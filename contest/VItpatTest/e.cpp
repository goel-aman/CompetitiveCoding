#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class elem{
    public:
    ll height;
    ll iq;
    ll ans;
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        elem arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i].height;
            arr[i].ans = 1;
        }
        for(ll i=0;i<n;i++){
            cin>>arr[i].iq;  
        }
        ll maxi = INT_MIN;
        arr[n - 1].ans = 1;
        for(ll i=n-2;i>=0;i--){
            arr[i].ans = 1;
            for(ll j = i + 1;j<n;j++){
                if(arr[i].height < arr[j].height && arr[i].iq > arr[j].iq){
                    arr[i].ans = max(arr[i].ans,arr[j].ans + 1);
                    maxi = max(maxi,arr[i].ans);
                }
            }
        }
        cout<<maxi<<endl;
    }
}