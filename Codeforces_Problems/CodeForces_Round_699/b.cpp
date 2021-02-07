#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll ans = -1;
        while(k >0){
            int newK = k;
            int flag = 1;
            for(ll j=1;j<n;j++){
                if(j == n - 1 && (a[j] == a[j - 1] || a[j] < a[j - 1]) ){
                    ans = -1;
                    flag = 0;
                    break;
                }

                if(a[j] > a[j - 1]){
                    ans = j;
                    a[j - 1] += 1;
                    k -= 1;
                    break;
                }

                if(a[j] <= a[j - 1]){
                    continue;
                }
                
            }

            if(flag == 0){
                break;
            }
            if(newK == k){
                ans = -1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}