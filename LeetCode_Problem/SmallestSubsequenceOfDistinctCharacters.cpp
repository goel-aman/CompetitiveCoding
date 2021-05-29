#include<bits/stdc++.h>
using namespace std;

// 1081. Smallest Subsequence of Distinct Characters
// Return the lexicographically smallest subsequence of s that
//  contains all the distinct characters of s exactly once.
// Note: This question is the same as 
// 316: https://leetcode.com/problems/remove-duplicate-letters/

// Example 1:
// Input: s = "bcabc"
// Output: "abc"

// Example 2:
// Input: s = "cbacdcbc"
// Output: "acdb"
 
// Constraints:
// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:
    string smallestSubsequence(string s) {
        int sLength = s.length();
        int count[26],used[26];
        for(int i=0;i<26;i++){
            count[i] = 0;
            used[i] = 0;
        }

        for(int i=0;i<sLength;i++){
            count[s[i] - 'a']++;
        }
        string ans = "";

        for(int i=0;i<sLength;i++){
            char ch = s[i] - 'a';
            count[ch]--;
            if(used[ch] > 0){
                continue;
            }


            while(ans.length() != 0 && (ans.back()-'a') > ch && count[ans.back() - 'a'] > 0){
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans += ch + 'a';
            used[ch] = 1;
        }
        return ans;
    }
};