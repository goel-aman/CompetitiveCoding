#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll p = 1, c = 1, m = 1;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'P'){
                p = 0;
            }

            if(s[i] == 'C'){
                c = 0;
            }

            if(s[i] == 'M'){
                m = 0;
            }
        }
        if(!p && !c && !m){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}