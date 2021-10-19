#include<bits/stdc++.h>
using namespace std;

// 1513. Number of Substrings With Only 1s

// Given a binary string s, return the number of 
// substrings with all characters 1's. Since the
//  answer may be too large, return it modulo 109 + 7.

// Example 1:
// Input: s = "0110111"
// Output: 9
// Explanation: There are 9 substring in total with
//  only 1's characters.
// "1" -> 5 times.
// "11" -> 3 times.
// "111" -> 1 time.

// Example 2:
// Input: s = "101"
// Output: 2
// Explanation: Substring "1" is shown 2 times in s.

// Example 3:
// Input: s = "111111"
// Output: 21
// Explanation: Each substring contains only 
// 1's characters.

// Example 4:
// Input: s = "000"
// Output: 0
 
// Constraints:
// 1 <= s.length <= 105
// s[i] is either '0' or '1'.


class Solution {
    int mod = 1e9 + 7;
public:
    int numSub(string s) {
        int sLength = s.length();
        long long int oneStreak = 0;
        long long int ans = 0;
        for(int i=0;i<sLength;i++){
            if(s[i] == '1'){
                oneStreak++;
            }
            else{
                ans = ans + (oneStreak * (oneStreak + 1))/2;
                ans = ans % mod;
                oneStreak = 0;
            }
        }
        if(oneStreak){
            ans = ans + (oneStreak * (oneStreak + 1))/2;
            ans = ans % mod;
        }
        return (int) ans;
    }
};