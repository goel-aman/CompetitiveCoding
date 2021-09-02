#include<bits/stdc++.h>
using namespace std;

bool alphaNumber(string s){
    int sLength = s.length();
    int alphaCount = 0,numberCount = 0;

    for(int i=0;i<sLength;i++){
        if(isalpha(s[i])){
            alphaCount++;
        } 

        if(s[i] > '0' && s[i] < '9'){
            numberCount++;
        }

        if(alphaCount > 0 && numberCount > 0){
            return true;
        }
    }
    return false;
}


int main(){
    string inputString;
    cin>>inputString;
    bool ans = alphaNumber(inputString);
    if(ans){
        cout<<"the string is alphaNumberic"<<endl;
    }else{
        cout<<"the string is not alphaNumeric"<<endl;
    }
    return 0;
}