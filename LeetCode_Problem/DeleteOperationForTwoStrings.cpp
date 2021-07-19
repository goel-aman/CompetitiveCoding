#include<bits/stdc++.h>
using namespace std;

// 583. Delete Operation for Two Strings
// Given two strings word1 and word2, 
// return the minimum number
//  of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character
//  in either string.

// Example 1:
// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and 
// another step to make "eat" to "ea".

// Example 2:
// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
 
// Constraints:
// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.

class Solution {
    int dp[501][501];
    int word1Length;
    int word2Length;
    string word11;
    string word22;
public:
    int longestCommon(int index1,int index2){
        if(index1 == word1Length || index2 == word2Length){
            return 0;
        }
        
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(word11[index1] == word22[index2]){
            return dp[index1][index2] = (1 + longestCommon(index1 + 1,index2 + 1));
        }

        int value1 = longestCommon(index1 + 1,index2);
        int value2 = longestCommon(index1,index2 + 1);

        return dp[index1][index2] = max(value1,value2);
    }

    int minDistance(string word1, string word2) {
        word1Length = word1.length();
        word2Length = word2.length();
        word11 = word1;
        word22 = word2;
        memset(dp,-1,sizeof(dp));
        int longest = longestCommon(0,0);
        return (word1Length + word2Length - (2*longest));
    }
};