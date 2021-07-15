#include<bits/stdc++.h>
using namespace std;

// 516. Longest Palindromic SubsequenceGiven a string s, find 
// the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another
//  sequence by deleting some or no elements without changing
//  the order of the remaining elements.

// Example 1:
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic
//  subsequence is "bbbb".

// Example 2:
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic
//  subsequence is "bb".
 
// Constraints:
// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

class Solution {
    int sLength;
public:
    int longestPalindromeSubseq(string s) {
        sLength = s.length();
        vector<vector<int>> vec(sLength,vector<int>(sLength,0));
        for(int i=0;i<sLength;i++){
            vec[i][i] = 1;
        }
        
        for(int i=1;i<sLength;i++){
            int start = 0;
            int end = 0 + i;
            while(end < sLength){
                if(s[start] == s[end]){
                    vec[start][end] = 2 + vec[start + 1][end - 1];
                    start++;
                    end++;
                    continue;
                }
                
                if(s[start] != s[end]){
                    vec[start][end] = max(vec[start + 1][end],vec[start][end - 1]);
                    start++;
                    end++;
                }
            }
        }
        return (vec[0][sLength - 1]);
    }
};