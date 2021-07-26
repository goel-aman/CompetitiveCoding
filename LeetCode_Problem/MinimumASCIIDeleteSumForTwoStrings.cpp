#include<bits/stdc++.h>
using namespace std;
        
// 712. Minimum ASCII Delete Sum for Two Strings
// Given two strings s1 and s2, return the lowest ASCII sum 
// of deleted characters to make two strings equal.

// Example 1:
// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value
//  of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is
//  the minimum sum possible to achieve this.
        
// Example 2:
// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string
//  into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer 
// is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we 
// would get answers of 433 or 417, which are higher.
 
// Constraints:
// 1 <= s1.length, s2.length <= 1000
// s1 and s2 consist of lowercase English letters.


class Solution {
    int s1Length;
    int s2Length;
    int dp[1001][1001];
    
public:
    int longestCommonSubsequence(string& s1,string& s2,int index1,int index2){
        if(index1 == s1Length and index2 == s2Length){
            return 0;
                    }


        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(index1 == s1Length){
            int sum = 0;
            for(int i=index2;i<s2Length;i++){
                sum += (int) s2[i];
            }
            return dp[index1][index2] = sum;
        }

        if(index2 == s2Length){
            int sum = 0;
            for(int i=index1;i<s1Length;i++){
                sum += (int) s1[i];
            }
            return dp[index1][index2] = sum;
        }

        
        if(s1[index1] == s2[index2]){
            return  dp[index1][index2] = longestCommonSubsequence(s1,s2,index1 + 1,index2 + 1);
        }
        
        
        int value1 = longestCommonSubsequence(s1,s2,index1 + 1,index2) + (int) s1[index1];
        int value2 = longestCommonSubsequence(s1,s2,index1,index2 + 1) + (int) s2[index2];
        
        if(value1 < value2){
            return dp[index1][index2] = value1;
        }
        
        return value2;
    }

    int minimumDeleteSum(string s1, string s2) {
        s1Length = s1.length();
        s2Length = s2.length();
        memset(dp,-1,sizeof(dp));
        int ans = longestCommonSubsequence(s1,s2,0,0);      
        return ans;
    }
};