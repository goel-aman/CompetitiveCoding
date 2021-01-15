#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll count = 0;
        for(ll i=n- 1;i>=0;i--){
            if(s[i] == ')'){
                count++;
                continue;
            }
            break;
        }
        if(count > (n - count)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"
        }
    }
    return 0;
}