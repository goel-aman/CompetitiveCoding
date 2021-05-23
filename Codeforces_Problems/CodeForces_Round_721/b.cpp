#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;
        cin>>s;
        int CountVar = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                CountVar++;
            }
        }
        if(CountVar == 1){
            cout<<"BOB"<<endl;
            continue;
        }
        if(CountVar%2 != 0){
            cout<<"ALICE"<<endl;
        }
        else{
            cout<<"BOB"<<endl;
        }
    }
    return 0;
}