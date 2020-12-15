#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s.length() == 4 && s!= "2020"){
            cout<<"NO"<<endl;
            continue;
        }
        if(s=="2020"){
            cout<<"YES"<<endl;
        }
        else if(s.length()<4 ||(s.length()==4 && s!="2020")){
            cout<<"NO"<<endl;
        }
        
        else {
            if(s.substr(0,4)=="2020"){
                cout<<"YES"<<endl;
            }
            
            else if(s.substr(0,3)=="202" && s.substr(n-1)=="0"){
                cout<<"YES"<<endl;
            }
            else if(s.substr(0,2)=="20" && s.substr(n-2)=="20"){
                cout<<"YES"<<endl;
            }
            else if(s.substr(0,1)=="2" && s.substr(n-3)=="020"){
                cout<<"YES"<<endl;
            }
            else if(s.substr(n-4)=="2020"){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}