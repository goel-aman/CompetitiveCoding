#include<bits/stdc++.h>
using namespace std;

// 1888. Minimum Number of Flips to Make the Binary String Alternating
// You are given a binary string s. You are allowed to perform two types
//  of operations on the string in any sequence:

// Type-1: Remove the character at the start of the string s and append
//  it to the end of the string.
// Type-2: Pick any character in s and flip its value, i.e., if its value
//  is '0' it becomes '1' and vice-versa.
// Return the minimum number of type-2 operations you need to perform such
//  that s becomes alternating.
// The string is called alternating if no two adjacent characters are equal.

// For example, the strings "010" and "1010" are alternating, while the 
// string "0100" is not.
 
// Example 1:
// Input: s = "111000"
// Output: 2
// Explanation: Use the first operation two times to make s = "100011".
// Then, use the second operation on the third and sixth elements to make s = "101010".

// Example 2:
// Input: s = "010"
// Output: 0
// Explanation: The string is already alternating.

// Example 3:
// Input: s = "1110"
// Output: 1
// Explanation: Use the second operation on the second element to make s = "1010".

// Constraints:
// 1 <= s.length <= 105
// s[i] is either '0' or '1'.


class Solution {
public:
    int minFlips(string s) {
        int sLength = s.length();   
        s = s + s;
        
        int ans = INT_MAX;
        // diff1 means starting from zero.
        int diff1 = 0, diff2 = 0;
        for(int i=0;i<sLength;i++){
            if(i%2 == 0){
                if(s[i] != '0'){
                    diff1++;
                }

                if(s[i] != '1'){
                    diff2++;
                }
            }

            if(i%2 != 0){
                if(s[i] != '1'){
                    diff1++;
                }

                if(s[i] != '0'){
                    diff2++;
                }
            }
        }
        ans = min({ans,diff1,diff2});

        for(int i=sLength;i<2*sLength;i++){
            if(i%2 == 0){
                if(s[i] != '0'){
                    diff1++;
                }

                if(s[i] != '1'){
                    diff2++;
                }
            }

            if(i%2 != 0){
                if(s[i] != '1'){
                    diff1++;
                }

                if(s[i] != '0'){
                    diff2++;
                }
            }

            int temp = i - sLength;
            if(temp%2 == 0){
                if(s[temp] != '0'){
                    diff1--;
                }

                if(s[temp] != '1'){
                    diff2--;
                }
            }

            if(temp%2 != 0){
                if(s[temp] != '1'){
                    diff1--;
                }

                if(s[temp] != '0'){
                    diff2--;
                }
            }
            ans = min({ans,diff1,diff2});
        }   

        return ans;
    }
};