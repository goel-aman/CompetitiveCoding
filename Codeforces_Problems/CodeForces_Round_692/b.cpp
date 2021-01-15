#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isDivisible(ll number){
    string s = to_string(number);
    for(int i=0;i<s.length();i++){
        if(s[i] == '0' ){
            continue;
        }
        if(number%(s[i] - '0') != 0){
            return false;
        }
    }
    return true;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll number = n;
        while(!isDivisible(number)){
            number++;
        }
        cout<<number<<endl;
    }
    return 0;
}