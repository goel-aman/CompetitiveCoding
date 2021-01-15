#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string s;
    cin>>s;
    unordered_map<char,int> um;
    ll max_count = 0;

    for(int i=0;i<s.length();i++){
        um[s[i]]++;
        if(um[s[i]] > max_count){
            max_count = um[s[i]];
        }
    }

    ll left_out = s.length() - max_count;
    if(left_out >= max_count){
        cout<<s.length()<<endl;
    }else{
        cout<<s.length() - (s.length() - max_count);
        cout<<endl;
    }
    return 0;
}