#include<bits/stdc++.h>
using namespace std;

// 1915. Number of Wonderful Substrings
// A wonderful string is a string where at most one letter 
// appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful, 
// but "ab" is not.
// Given a string word that consists of the first ten lowercase
//  English letters ('a' through 'j'), return the number of 
// wonderful non-empty substrings in word. If the same substring
//  appears multiple times in word, then count each occurrence
//  separately.
// A substring is a contiguous sequence of characters in a string.

// Example 1:
// Input: word = "aba"
// Output: 4
// Explanation: The four wonderful substrings are underlined below:
// - "aba" -> "a"
// - "aba" -> "b"
// - "aba" -> "a"
// - "aba" -> "aba"

// Example 2:
// Input: word = "aabb"
// Output: 9
// Explanation: The nine wonderful substrings are underlined below:
// - "aabb" -> "a"
// - "aabb" -> "aa"
// - "aabb" -> "aab"
// - "aabb" -> "aabb"
// - "aabb" -> "a"
// - "aabb" -> "abb"
// - "aabb" -> "b"
// - "aabb" -> "bb"
// - "aabb" -> "b"

// Example 3:
// Input: word = "he"
// Output: 2
// Explanation: The two wonderful substrings are underlined below:
// - "he" -> "h"
// - "he" -> "e"
 
// Constraints:
// 1 <= word.length <= 105
// word consists of lowercase English letters from 'a' to 'j'.

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long int ans = 0;
        unordered_map<int,long long int> um;
        int sum = 0;
        um[0] = 1;
        for(int i=0;i<word.length();i++){
            int index = word[i] - 'a';
            sum ^= (1 << index);

            // lets sum up total even occurences.
            if(um.count(sum)){
                ans += um[sum];
            }

            for(int i=0;i<10;i++){
                int temp = sum;
                int tempValue = sum ^ (1 << i);
                if(um.count(tempValue)){
                    ans += um[tempValue];
                }
            }
            um[sum]++;
        }      
        return ans;
    }
};