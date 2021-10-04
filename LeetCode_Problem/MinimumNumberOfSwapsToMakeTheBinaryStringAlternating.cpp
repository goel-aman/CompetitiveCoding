#include<bits/stdc++.h>
using namespace std;

// 1864. Minimum Number of Swaps to Make the Binary String Alternating
// Given a binary string s, return the minimum number of character swaps
//  to make it alternating, or -1 if it is impossible.
// The string is called alternating if no two adjacent characters are equal. 
// For example, the strings "010" and "1010" are alternating, while the string
//  "0100" is not.
// Any two characters may be swapped, even if they are not adjacent.

// Example 1:
// Input: s = "111000"
// Output: 1
// Explanation: Swap positions 1 and 4: "111000" -> "101010"
// The string is now alternating.

// Example 2:
// Input: s = "010"
// Output: 0
// Explanation: The string is already alternating, no swaps are needed.

// Example 3:
// Input: s = "1110"
// Output: -1
 
// Constraints:
// 1 <= s.length <= 1000
// s[i] is either '0' or '1'.


class Solution {
public:
    int minSwaps(string s) {
        int sLength = s.length(),countZero = 0,countOne = 0;
        for(int i=0;i<sLength;i++){
            if(s[i] == '0'){
                countZero++;
            }

            if(s[i] == '1'){
                countOne++;
            }
        }
        int difference = abs(countZero - countOne);
        if(difference > 1){
            return -1;
        }
        // int ans = 0;
        int swapFirst = 0,swapSecond = 0;
        // even -> 0 , odd -> 1
        for(int i=0;i<sLength;i++){
            if(i%2 == 0 && s[i] != '0'){
                swapFirst++;
            }

            if(i%2 != 0 && s[i] != '1'){
                swapFirst++;
            }
        }

        // even -> 1 , odd -> 0
        for(int i=0;i<sLength;i++){
            if(i%2 == 0 && s[i] != '1'){
                swapSecond++;
            }

            if(i%2 != 0 && s[i] != '0'){
                swapSecond++;
            }
        }
        int ans = INT_MAX;
        if(swapFirst%2 == 0){
            ans = min(ans,swapFirst/2);
        }
        if(swapSecond%2 == 0){
            ans = min(ans,swapSecond/2);
        }
        if(ans == INT_MAX){
            return 0;
        }
        // int ans = min(swapFirst/2,swapSecond/2);
        return ans;
    }   
};