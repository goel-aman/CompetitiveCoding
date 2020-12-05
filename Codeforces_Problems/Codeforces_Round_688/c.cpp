#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
       ll n;
       cin>>n;
       ll arr[n];
       for(int i=0;i<n;i++)
       {
          cin>>arr[i];
       }
        if(n <= 2){
            cout<<0<<endl;
            continue;
        }

        if(n == 3)
        {
            cout<<min(min(abs(arr[0] - arr[2]),abs(arr[1] - arr[2])), min(abs(arr[0] - arr[2]),abs(arr[0] - arr[1])))<<endl;
            continue;
        }

    ll sum = 0;
       for(int i=1;i<n - 2;i++){
        
           sum += abs(arr[i] - arr[i - 1]);
       }
        sum += min(abs(arr[n -3] - arr[n -2]),abs(arr[n - 3] - arr[n - 1]));
    
       ll sum2 = 0;
       for(int i=3;i<n;i++){
           sum2 += abs(arr[i] - arr[i - 1]);
       }
       sum2 += min( abs(arr[0] - arr[2]), abs(arr[1] - arr[2]));
       ll ans = min(sum,sum2);
       cout<<ans<<endl;
    }
    return 0;
}