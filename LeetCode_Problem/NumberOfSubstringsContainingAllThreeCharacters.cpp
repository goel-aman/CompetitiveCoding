#include<bits/stdc++.h>
using namespace std;

// 1358. Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one 
// occurrence of all these characters a, b and c.

// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence
//  of the characters a, b and c are "abc", "abca", "abcab", "abcabc",
//  "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of 
// the characters a, b and c are "aaacb", "aacb" and "acb". 

// Example 3:
// Input: s = "abc"
// Output: 1
 
// Constraints:
// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        int sLength = s.length();
        int aCount = 0;
        int bCount = 0;
        int cCount = 0;
        int ans = 0;
        if(sLength < 3){
            return 0;
        }

        int start = 0,end = 0;
        while(start <= end && end < sLength){
            if(s[end] == 'a'){
                aCount++;
            }   

            if(s[end] == 'b'){
                bCount++;
            }

            if(s[end] == 'c'){
                cCount++;
            }

            while(aCount > 0 && bCount > 0 && cCount > 0){
                ans += 1;
                ans += (sLength - end - 1);
                if(s[start] == 'a'){
                    aCount--;
                }

                if(s[start] == 'b'){
                    bCount--;
                }

                if(s[start] == 'c'){
                    cCount--;
                }

                start++;     
            }
            end++;
            continue;
        }
        return ans;        
    }
};