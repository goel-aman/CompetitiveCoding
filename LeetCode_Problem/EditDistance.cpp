#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minDistance(string word1,string word2){
        int siz = max(word1.length(),word2.length());
        int dp[1000][1000];
        memset(dp,-1,sizeof(dp));
        return minDistance(word1,word2,dp);
    }
    
    int minDistance(string word1, string word2,int dp[1000][1000]) {
        if(word1.length() == 0 && word2.length() == 0){
            return 0;
        }
        
        if(word1.length() != 0 && word2.length() == 0){
            return word1.length();
        }
        
        if(word1.length() == 0 && word2.length() != 0){
            return word2.length();
        }
        
        if(dp[word1.length()][word2.length()] != -1){
            return dp[word1.length()][word2.length()];
        }
        
        int a = INT_MAX;
        if(word1[0] == word2[0]){
            a = minDistance(word1.substr(1),word2.substr(1),dp);
        }
        int b = minDistance(word1.substr(1),word2.substr(1),dp) + 1;
        int c = minDistance(word1.substr(1),word2,dp) + 1;
        int d = minDistance(word1,word2.substr(1),dp) + 1;
        return dp[word1.length()][word2.length()] = min(a,min(b,min(c,d)));
    }
};