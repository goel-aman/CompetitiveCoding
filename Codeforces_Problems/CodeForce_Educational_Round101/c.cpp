#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s; 
        ll n = s.length();
        if(n%2 != 0){
            cout<<"NO"<<endl;
            continue;
        }
        if(s[0] == ')' || s[n - 1] == '('){
            cout<<"NO"<<endl;
            continue;
        }
        
        ll count = 0;
        for(ll i=0;i<n;i++){
            if(s[i] == '?'){
                count++;
            }
        }
        if(count%2 != 0){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
    }
    return 0;
}