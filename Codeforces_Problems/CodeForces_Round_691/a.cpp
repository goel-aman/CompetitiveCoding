#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string rr;
        cin>>rr;
        string bb;
        cin>>bb;
        ll r[n];
        for(ll i=0;i<n;i++){
            r[i] = rr[i] + '0';
        }
        ll b[n];
        for(ll i=0;i<n;i++){
            b[i] = bb[i] + '0';
        }
        // sort(r, r + n);
        // sort(b,b + n);
        ll red_count = 0;
        ll blue_count = 0;
        ll equal_count = 0;
        for(ll i=n - 1;i>=0;i--){
            if(r[i] > b[i]){
                red_count++;
                continue;
            }
            if(b[i] > r[i]){
                blue_count++;
                continue;
            }
            equal_count++;
        }

        if(equal_count == n){
            cout<<"EQUAL"<<endl;
            continue;
        }
        if(red_count == blue_count){
            cout<<"EQUAL"<<endl;
            continue;
        }
        if(red_count > blue_count){
            cout<<"RED"<<endl;
        }
        else{
            cout<<"BLUE"<<endl;
        }

    }
    return 0;
}