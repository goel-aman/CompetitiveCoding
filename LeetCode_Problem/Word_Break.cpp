// #include<bits/stdc++.h>
// #include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> ma;
        for(int i=0;i<wordDict.size();i++){
            ma[wordDict[i]] = true;
        }
         
        bool dp[n + 1];
        memset(dp,0,sizeof(dp));
        dp[n]= 1;
        for(int i = n - 1;i>= 0;i++){
            for(int j = i + 1 ; j < n; j++){
                string substring = s.substr(i,j - i + 1);
                if(ma[substring] = true && dp[j + 1] == 1 ){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};