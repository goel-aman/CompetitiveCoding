#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(b > a){
            cout<<1<<endl;
            continue;
        }

        if(b == a){
            cout<<2<<endl;
            continue;
        }
        ll initialb = b;
        ll step = 0;
        if(b == 1){
            b = 2; 
            step++;
        }

        ll tempa = a;
        while(tempa > 0){
            tempa = tempa / b;
            step++;
        }
        // cout<<"step value is : "<<step<<endl;
        ll i = b + 1;
        // cout<<"Value of i is : "<<i<<endl;
        while(true){
            ll tema = a;
            ll steptemp = i - initialb;
            // cout<<"Value of inital step temp is : "<<steptemp<<endl;
            while(tema > 0){
                tema = tema / i;
                steptemp++;
            }
            // cout<<"steptemp is : "<<steptemp<<endl;
            if(steptemp <= step){
                step = steptemp;
                i = i + 1;
            }
            else{
                break;
            }
        }
        cout<<step<<endl;
    }
}