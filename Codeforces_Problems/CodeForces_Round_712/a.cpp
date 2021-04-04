#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalindromic(string s){
    int sLength = s.length();
    for(int i=0;i<sLength/2;i++){
        if(s[i] != s[sLength - 1 - i]){
            return false;
        }
    }
    return true;
}

bool ifOnlyA(string s){
    int sLength = s.length();
    for(int i=0;i<sLength;i++){
        if(s[i] != 'a'){
            return false;
        }
    }
    return true;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string charr = "a";
        int sLength = s.length();
        if(ifOnlyA(s) == true){
            cout<<"NO"<<endl;
            continue;
        }
        int gotanswer = 0;
        int i = 0;
        int j = sLength - 1;
        while(i <= j){
            if(i == j && s[i] == 'a'){
                break;
            }

            if(s[i] == 'a' && s[j] == 'a'){
                i++;j--;
            }else{
                if(s[j] == 'a'){
                    cout<<"YES"<<endl;
                    gotanswer = 1;
                    cout<<s.substr(0,j) + "a" + s.substr(j)<<endl;
                    break;
                }
                else{
                    cout<<"YES"<<endl;
                    gotanswer = 1;
                    cout<<s.substr(0,i) + "a" + s.substr(i)<<endl;
                    break;
                }
                
            }
        }
        if(gotanswer == 0){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}