#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll ans = 1;
        ll n;
        cin>>n;
        ll state = 0;
        while(n--){
            string s;
            cin>>s;
            if(s == "start"){
                state = 1;
                continue;
            }
            if(s == "restart"){
                state = 1;
                continue;
            }

            if(s == "stop" && state == 0){
                ans = 0;
                break;
            }
            if(s == "stop"){
                state = 0;
                continue;
            }

        }
        if(ans == 0){
            cout<<"404"<<endl;
        }else{
            cout<<"200"<<endl;
        }
    }
}