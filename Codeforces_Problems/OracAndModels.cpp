#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// B. Orac and Models

int main(){
    ll t;
    cin>>t;
    while(t--){
        // cin>>t;
        ll n;
        cin>>n;
        ll arr[n + 1];
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
        }

        ll ans[n + 1];
        memset(ans,0,sizeof(ans));
        ans[0] = 1;
        ans[1] = 1;
        ll ret = 1;
        for(int i=2;i<=n;i++){
            ll maxValue = 0;
            for(int j=1;j<=sqrt(i);j++){
                if(i%j == 0){
                    ll temp = j;
                    ll temp2 = i/j;
                    if(arr[temp] < arr[i]){
                        maxValue = max(maxValue,ans[temp] + 1);
                    }

                    if(arr[temp2] < arr[i]){
                        maxValue = max(maxValue,ans[temp2] + 1);
                    }
                }
            }
            ans[i] = max(maxValue,(long long) 1);
            ret = max(ret,ans[i]);
        }
        cout<<ret<<endl;
    }
}