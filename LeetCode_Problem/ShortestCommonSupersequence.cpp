// 1092. Shortest Common Supersequence
#include<bits/stdc++.h>
using namespace std;

// Given two strings str1 and str2, return the shortest string that has both str1
//  and str2 as subsequences.  If multiple answers exist, you may return any of them.
// (A string S is a subsequence of string T if deleting some number of characters from
//  T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

// Example 1:
// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
 
// Note:
// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.

class Solution {
public:
    string lcs(string first,string second){
        int firstLength = first.length();
        int secondLength = second.length();

        if(firstLength == 0 || secondLength == 0){
            string output = "";
            return output;
        }

        string dp[firstLength + 1][secondLength + 1];
        for(int i = 0;i<firstLength + 1;i++){
            dp[i][0] = "";
        }

        for(int i = 0;i<secondLength + 1;i++){
            dp[0][i] = "";
        }

        for(int i=1;i<firstLength + 1;i++){
            for(int j=1;j<secondLength + 1;j++){
                if(first[i - 1] == second[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + first[i - 1];
                }
                else{
                    if(dp[i - 1][j].length() >= dp[i][j - 1].length()){
                        dp[i][j] = dp[i - 1][j];
                    }else{
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
        return dp[firstLength][secondLength];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcsValue = lcs(str1,str2);
        int i = 0 , j = 0;
        string res = "";
        for(auto c : lcsValue){
            while(str1[i] != c){
                res += str1[i];
                i++;
            }

            while(str2[j] != c){
                res += str2[j];
                j++;
            }

            res += c;
            i++;
            j++;
        }
        res += str1.substr(i) + str2.substr(j);
        return res;
    }
};