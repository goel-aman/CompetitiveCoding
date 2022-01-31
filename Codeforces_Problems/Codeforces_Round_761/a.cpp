#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string inputT;
        cin>>inputT;
        sort(s.begin(),s.end());

        ll countA = 0,countB = 0,countC = 0;
        ll sLength = s.length();
        ll breakPoint = sLength;
        for(ll i=0;i<sLength;i++){
            if(s[i] == 'a'){
                countA++;
            }

            if(s[i] == 'b'){
                countB++;
            }

            if(s[i] == 'c'){
                countC++;
            }

            if(s[i] != 'a' && s[i] != 'b' & s[i] != 'c'){
                breakPoint = i;
                break;
            }
        }
        if(countA == 0){
            cout<<s<<endl;
            continue;
        }

        string leftOut = s.substr(breakPoint);
        string ret = "";
        if(inputT == "abc"){
            for(ll i=0;i<countA;i++){
                ret += "a";
            }

            for(ll i=0;i<countC;i++){
                ret += "c";
            }

            for(ll i=0;i<countB;i++){
                ret += "b";
            }

            ret += leftOut;
            cout<<ret<<endl;
            continue;
        }       

        cout<<s<<endl;

    }
}