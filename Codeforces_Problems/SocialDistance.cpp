#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans = 0;
        if(s[0] == '0'){
            int sum = 0;
            for(ll i=0;i<=min(n -1,k);i++){
                if(s[i] == '1'){
                    sum++;
                }
            }
            if(sum == 0){
                s[0] = '1';
                ans++;
            }
        }
        // cout<<"answer is: "<<ans<<endl;
        if(s[n - 1] == '0'){
            int sum = 0;
            for(ll i=n-1;i>=max((ll)0,n - 1 - k);i--){
                if(s[i] == '1'){
                    sum++;
                }
            }
            // cout<<"sum si: "<<sum<<endl;
            if(sum == 0){
                s[n - 1] = '1';
                ans++;
            }
        }
        // cout<<"answer is : : "<<ans<<endl;
        ll sum = 0;
        ll seg = (2 * k) + 1;
        for(ll i=0;i<n;i++){
            if(i >= seg){
                // cout<<"value of is : i"<<i<<" and value of sum is : "<<sum<<endl;
                if(sum == 0){
                    ans++;
                    s[i - k - 1] = '1';
                    sum++;
                }
                if(s[i - seg] == '1'){
                    sum -= 1;
                }
            }
    
            if(s[i] == '1'){
                sum++;
            }
        }
        cout<<ans<<endl;     
    }
}