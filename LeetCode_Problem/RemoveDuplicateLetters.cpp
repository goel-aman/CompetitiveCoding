#include<bits/stdc++.h>
using namespace std;

// 316. Remove Duplicate Letters

// Given a string s, remove duplicate letters so that every letter
//  appears once and only once. You must make sure your result is 
// the smallest in lexicographical order among all possible results.

// Example 1:
// Input: s = "bcabc"
// Output: "abc"

// Example 2:
// Input: s = "cbacdcbc"
// Output: "acdb"
 
// Constraints:
// 1 <= s.length <= 104
// s consists of lowercase English letters.
 

// Note: This question is the same as 1081
// : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/


class Solution {
public:
    string removeDuplicateLetters(string s) {
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
            int ch = s[i] - 'a';
            count[ch]--;
            if(used[ch] > 0){
                continue;
            }

            while(ans.length() != 0 && ch < (s[ans.length() - 1] - 'a') && count[s[ans.length() - 1] - 'a'] > 0){
                used[s[i] - 'a'];
                ans.pop_back();
            }
            used[ch] = 1;
            ans.push_back(ch + 'a');
        }
        return ans;
    }
};