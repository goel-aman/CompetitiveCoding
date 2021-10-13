#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        if(a == 1){
            if((n - 1)%b == 0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
                
            }
            continue;
        }
        ll temp = 1;
        int gotAnswer = 0;
        while(temp <= n){
            if((n - temp)%b == 0){
                cout<<"Yes"<<endl;
                gotAnswer = 1;
                break;
                // continue;
            }

            temp *= a;
        }
        if(!gotAnswer){
            cout<<"No"<<endl;
        }
    }
    return 0;
}