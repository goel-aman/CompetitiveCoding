#include<bits/stdc++.h>
using namespace std;

// 159. Longest Substring with At Most Two Distinct Characters

// Given a string s, return the length of the longest substring that contains at most two distinct characters.

 

// Example 1:

// Input: s = "eceba"
// Output: 3
// Explanation: The substring is "ece" which its length is 3.
// Example 2:

// Input: s = "ccaabbb"
// Output: 5
// Explanation: The substring is "aabbb" which its length is 5.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of English letters.


class Solution {
    unordered_map<char,int> frequency;
    unordered_set<char> unique;

public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        int sLength = s.length();
        int startingIndex = 0;
        for(int i=0;i<sLength;i++){
            char value = s[i];
            frequency[value]++;
            unique.insert(value);
            while(unique.size() > 2){
                frequency[s[startingIndex]]--;
                if(frequency[s[startingIndex]] == 0){
                    frequency.erase(s[startingIndex]);
                    unique.erase(s[startingIndex]);
                }
                startingIndex++;
            }
            ans = max(ans,i - startingIndex + 1);
        }
        return ans;
    }
};