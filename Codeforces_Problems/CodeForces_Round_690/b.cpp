#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
#define mod 1000000007 // equal to 10^9 + 7
#define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(s == "2020")
        {
            cout<<"YES"<<endl;
            continue;
        }
        int length = s.length();
        if(length < 4){
            cout<<"NO"<<endl;
            continue;
        }
        if(length == 4 && s != "2020"){
            cout<<"NO"<<endl;
            continue;
        }
        if(s.substr(length - 4) == "2020"){
            cout<<"YES"<<endl;
            continue;
        }
        if(s[0] == '2' && s.substr(length - 3) == "020"){
            cout<<"YES"<<endl;
            continue;
        }
        if(s.substr(0,2) == "20" && s.substr(length - 2) == "20"){
            cout<<"YES"<<endl;
            continue;
        }

        if(s.substr(0,3) == "202" && s.substr(length -1) == "0"){
            cout<<"YES"<<endl;
            continue;
        }

        if(s.substr(0,4) == "2020"){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}