#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll countN = 0;
        ll countE = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'E'){
                countE++;
            }

            if(s[i] == 'N'){
                countN++;
            }
        }

        if(countN == 1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}