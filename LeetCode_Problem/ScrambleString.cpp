#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,bool> um;    
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        
        if(s1.length() != s2.length()){
            return false;
        }

        if(s1.length() <= 1){
            return false;
        }

        string val = s1 + ";" + s2;
        if(um.count(val) > 0){
            return um[val];
        }

        int length = s1.length();
        bool ans = false;
        for(int i=1;i<=length-1;i++){
            if( (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))  ||  (isScramble(s1.substr(0,i),s2.substr(length - i))  && isScramble(s1.substr(i),s2.substr(0,length - i)) )       ){
                ans = true;
                break;
            }
        }
        return um[val] = ans;
    }
};