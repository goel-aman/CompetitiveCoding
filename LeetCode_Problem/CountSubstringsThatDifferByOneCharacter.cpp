#include<bits/stdc++.h>
using namespace std;

// 1638. Count Substrings That Differ by One Character
// Given two strings s and t, find the number of ways you can 
// choose a non-empty substring of s and replace a single character
//  by a different character such that the resulting substring is a
//  substring of t. In other words, find the number of substrings in
//  s that differ from some substring in t by exactly one character.
// For example, the underlined substrings in "computer" and "computation"
//  only differ by the 'e'/'a', so this is a valid way.
// Return the number of substrings that satisfy the condition above.
// A substring is a contiguous sequence of characters within a string.

// Example 1:
// Input: s = "aba", t = "baba"
// Output: 6
// Explanation: The following are the pairs of substrings from s and t 
// that differ by exactly 1 character:
// ("aba", "baba")
// ("aba", "baba")
// ("aba", "baba")
// ("aba", "baba")
// ("aba", "baba")
// ("aba", "baba")
// The underlined portions are the substrings that are chosen from s and t.

// ​​Example 2:
// Input: s = "ab", t = "bb"
// Output: 3
// Explanation: The following are the pairs of substrings from s and t
//  that differ by 1 character:
// ("ab", "bb")
// ("ab", "bb")
// ("ab", "bb")
// ​​​​The underlined portions are the substrings that are chosen from s and t.

// Example 3:
// Input: s = "a", t = "a"
// Output: 0

// Example 4:
// Input: s = "abe", t = "bbc"
// Output: 10
 
// Constraints:
// 1 <= s.length, t.length <= 100
// s and t consist of lowercase English letters only.


class Solution {
public:
    int countSubstrings(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        int ans = 0;
        for(int i=0;i<sLength;i++){
            for(int j=0;j<tLength;j++){
                int a = i;
                int b = j;
                int difference = 0;
                while(a < sLength && b < tLength){
                    if(s[a] == t[b]){
                        a++;
                        b++;
                        if(difference == 1){
                            ans++;
                        }
                        continue;
                    }
                    difference++;
                    if(difference == 1){
                        ans++;
                    }

                    if(difference == 2){
                        break;
                    }
                    a++;
                    b++;
                }
            }
        }
        return ans;
    }
};