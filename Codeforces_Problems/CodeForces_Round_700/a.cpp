#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int stringLength = s.length();
        for(int i=0;i<stringLength;i++){
            if(i%2 == 0){
                if(s[i] != 'a'){
                    s[i] = 'a';
                }else{
                    s[i] = 'b';
                }
            }
            else{
                if(s[i] != 'z'){
                    s[i] = 'z';
                }else{
                    s[i] = 'y';
                }
            }
        }
        cout<<s<<endl;
    }
}