#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    int gotAnswer = false; 
    while(t--){
        ll n; cin>>n;
        if(n%2 != 0){
            cout<<"NO"<<endl;
            continue;
        }
        int power2 = 0;
        while(true){
            while(n%2 == 0){
                n = n / 2;
                power2++;
            }

            int val = sqrt(n);
            // cout<<"value of val is : "<<val<<endl;
            if(power2 == 0){
                cout<<"NO"<<endl;
                continue;
            }
            // cout<<"hello"<<endl;
            if((double) (val * val) == n){
                // cout<<"hello"<<endl;
                gotAnswer = true;
            }
            else{
                gotAnswer = false;
            }
            break;
        }
        if(gotAnswer == true){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}