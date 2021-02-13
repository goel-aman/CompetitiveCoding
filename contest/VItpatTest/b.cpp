#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll ans = 1;
        ll n;
        cin>>n;
        ll state = 0;
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            string s = arr[i];
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