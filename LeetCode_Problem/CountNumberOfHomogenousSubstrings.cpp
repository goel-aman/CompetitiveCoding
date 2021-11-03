#include<bits/stdc++.h>
using namespace std;

// 1759. Count Number of Homogenous Substrings
// Given a string s, return the number of homogenous 
// substrings of s. Since the answer may be too 
// large, return it modulo 109 + 7.

// A string is homogenous if all the characters of
//  the string are the same.
// A substring is a contiguous sequence of characters
//  within a string.

// Example 1:
// Input: s = "abbcccaa"
// Output: 13
// Explanation: The homogenous substrings are listed
//  as below:
// "a"   appears 3 times.
// "aa"  appears 1 time.
// "b"   appears 2 times.
// "bb"  appears 1 time.
// "c"   appears 3 times.
// "cc"  appears 2 times.
// "ccc" appears 1 time.
// 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.

// Example 2:
// Input: s = "xy"
// Output: 2
// Explanation: The homogenous substrings are "x" and "y".

// Example 3:
// Input: s = "zzzzz"
// Output: 15
 
// Constraints:
// 1 <= s.length <= 105
// s consists of lowercase letters.


class Solution {
    int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int sLength = s.length();
        long long int streak = 1;
        long long int ans = 0;
        char prev = s[0];
        for(int i=1;i<sLength;i++){
            if(s[i] == prev){
                streak++;
                continue;
            }
            
            ans = (ans + ((streak * (streak + 1))/2))%mod;
            prev = s[i];
            streak = 1;
        }
        ans = (ans + (((long long)streak * (long long)(streak + 1))/2))%mod;
        return ans;
    }
};