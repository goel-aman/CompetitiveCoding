#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// C. Permutation Partitions

int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    ll mod = 998244353;
    if(n == k){
        cout<<sum<<" "<<1<<endl;
        return 0;
    }
    ll ans = 0;
    for(ll i=n, j =0;j < k && i>=0;i--,j++){
        ans += i;
    }
    ll prev = -1;
    ll value = 1;
    for(int i=0;i<n;i++){
        if(arr[i] <= n && arr[i] >= n - k + 1){
            if(prev == -1){
                prev = i;
                continue;
            }else{
                value = value * (i - prev);
                value %= mod;
                prev = i;
            }
        }
    }
    ll output = value % mod;
    cout<<ans<<" "<<output<<endl;
}