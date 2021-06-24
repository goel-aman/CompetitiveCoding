#include<bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring 
// without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Example 4:
// Input: s = ""
// Output: 0
 
// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLength = s.length();
        int start = 0;
        int end = 0;
        int length = 0;
        unordered_map<char,bool> um;
        int maxLength = 0;
        for(int i=0;i<sLength;i++){
            um[s[i]] = false;
        }

        while(end < sLength){
            if(um[s[end]] == false){
                um[s[end]] = true;
                end++;
                length++;
                // cout<<
                maxLength = max(length,maxLength);
                continue;
            }
            
            if(um[s[end]] == true){
                um[s[start]] = false;
                start++;
                length--;
                continue;
            }
        }
        return maxLength;
    }
};