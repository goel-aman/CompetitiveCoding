#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
// #define mod 1000000007 // equal to 10^9 + 7
// #define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        if(x <= 9){
            cout<<x<<endl;
            continue;
        }
        string ans = "";
        ll sum = 0;
        for(int i=9;i>=0;i--){
            sum +=i;
            if(sum == x ){
                ans += to_string(i);
                break;
            }
            if(sum < x){
                ans += to_string(i);
                continue;
            }
            if(sum > x){
                sum -= i;
                continue;
            }
        }
        if(sum != x){
            cout<<-1<<endl;
            continue;
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}