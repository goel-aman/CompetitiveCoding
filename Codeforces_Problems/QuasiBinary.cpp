#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;   
    cin>>n;
    string input = to_string(n);
    vector<string> ans;
    while(n > 0){
        ll inputLength = input.length();
        string s= "";
        for(int i=0;i<inputLength;i++){
            if(input[i] == '0'){
                s += '0';
            }else{
                s += '1';
                input[i] = input[i] - 1;
            }
        }
        ans.push_back(s);
        n = stoi(input);
        input = to_string(n);
        inputLength = input.length();
    }
    cout<<ans.size()<<endl;
    for(auto &var : ans){
        cout<<var<<" ";
    }
    cout<<endl;
}