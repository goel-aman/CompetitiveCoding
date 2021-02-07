#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main(){
    ll t;
    cin>>t;
    while(t--){
        ll px,py;
        cin>>px>>py;
        string s;
        cin>>s;
        ll xpositive = 0;
        ll xnegative = 0;
        ll ypositive = 0;
        ll ynegative = 0;
        for(int i=0;i<s.length();i++){
        
            if(s[i] == 'R'){
                xpositive++;
            }

            if(s[i] == 'L'){
                xnegative++;
            }
            if(s[i] == 'U'){
                ypositive++;
            }

            if(s[i] == 'D'){
                ynegative++;
            }
        }
        bool xsatisfy = true;
        if(px < 0){
            if(abs(px) > xnegative){
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(px > 0){
            if(abs(px) > xpositive){
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(py > 0){
            if(abs(py) > ypositive){
                cout<<"NO"<<endl;
                continue;
            }
        }
        if(py < 0)
        {
            if(abs(py) > ynegative){
                cout<<"NO"<<endl;
                continue;
            }
        }
        cout<<"YES"<<endl;

    }
    return 0;
}