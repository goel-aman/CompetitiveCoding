#include<bits/stdc++.h>
using namespace std;

// 1312. Minimum Insertion Steps to Make a String Palindrome
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:
// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we don't need any insertions.

// Example 2:
// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".

// Example 3:
// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

// Example 4:
// Input: s = "g"
// Output: 0

// Example 5:
// Input: s = "no"
// Output: 1
 
// Constraints:
// 1 <= s.length <= 500
// All characters of s are lower case English letters.

class Solution {
    int **dp;

public:
    Solution(){
        dp = new int*[501];
        for(int i=0;i<=500;i++){
            dp[i] = new int[501];
            for(int j=0;j<=500;j++){
                dp[i][j] = -1;
            }
        }
    }
    int minInsertion(string &s,int start,int end){
        int sLength = end - start + 1;
        if(sLength == 0 || sLength == 1){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        if(s[start] == s[end]){
            start++;
            end--;
            return dp[start][end] = minInsertion(s,start,end);
        }

        return dp[start][end] = ( min(minInsertion(s,start + 1,end),minInsertion(s,start,end - 1)) + 1);
    }

    int minInsertions(string s) {
        int sLength = s.length();
        return minInsertion(s,0,sLength - 1);
    }
};