#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,int> um;
public:
    int numDistinct(string s, string t) {
        int slength = s.length();
        int tlength = t.length();
        
        if(t.length() == 0){
            return 1;
        }
        
        if(s.length() == 0 && t.length() != 0){
            return 0;
        }
        string val = s+ ";" + t;
        if(um.count(val) > 0){
            return um[val];
        }
        int ans = 0;
        
        for(int i=0;i<slength;i++){
            if(t[0] == s[i]){
                ans += numDistinct(s.substr(i + 1),t.substr(1));
            }
        }
        um[val] = ans;
        return ans;
    }
};