#include<bits/stdc++.h>
using namespace std;cd 
class Solution {
    unordered_map<string,bool> um;
    unordered_map<string,vector<string>> umm;
public:
    
    vector<string> wordBreak2(string s){
        vector<string> ans;

        int slength = s.length();
        if(slength == 0){
            ans.push_back("");
            return ans;
        }
        
        if(umm.count(s) > 0){
            return umm[s];
        }

        for(int i=1;i<=slength;i++){
            string substring = s.substr(0,i);
            if(um.count(substring) > 0){
                vector<string> vv = wordBreak2(s.substr(i));
                for(auto it : vv){
                    if(it == ""){
                        ans.push_back(substring);
                        continue;
                    }
                    ans.push_back(substring + " " + it);
                }
            }
        }
        return (umm[s] = ans);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto a : wordDict){
            um[a] = true;
        }
        um[""] = true;
        vector<string> ans = wordBreak2(s);
        um.clear();
        return ans;
    }
    
};