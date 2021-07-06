#include<bits/stdc++.h>
using namespace std;

// 424. Longest Repeating Character Replacement
// You are given a string s and an integer k. You can choose
//  any character of the string and change it to any other uppercase
//  English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter
//  you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

// Constraints:
// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

class Solution {
public:
    int characterReplacement(string s, int k) {
        int sLength = s.length();
        vector<int> charCount(26,0);

        int maxLength = 0;
        int maxCount = 0;
        int windowStart = 0;
        int windowEnd = 0;
        for(int i=0;i<sLength;i++){
            charCount[s[i] - 'A']++;
            maxCount = max(maxCount,charCount[s[i] - 'A']);
            windowEnd = i;    
            while(windowEnd - windowStart + 1 - maxCount > k){
                charCount[s[windowStart] - 'A']--;
                windowStart++;
            }
            maxLength = max(maxLength,windowEnd - windowStart + 1);
    
            for(int i=0;i<26;i++)
            {
                maxCount = max(charCount[i],maxCount);
            }
        }
        return maxLength;
    }
};