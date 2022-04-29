#include<bits/stdc++.h>
using namespace std;

// 1180. Count Substrings with Only One Distinct Letter
// Given a string s, return the number of substrings that
//  have only one distinct letter.

// Example 1:
// Input: s = "aaaba"
// Output: 8
// Explanation: The substrings with one distinct letter 
// are "aaa", "aa", "a", "b".
// "aaa" occurs 1 time.
// "aa" occurs 2 times.
// "a" occurs 4 times.
// "b" occurs 1 time.
// So the answer is 1 + 2 + 4 + 1 = 8.

// Example 2:
// Input: s = "aaaaaaaaaa"
// Output: 55

// Constraints:
// 1 <= s.length <= 1000
// s[i] consists of only lowercase English letters.

class Solution {
public:
    int countLetters(string s) {
        int sLength = s.length();
        
        if(sLength == 0){
            return 0;
        }
        
        
        int streak = 1;
        char alphabet = s[0];
        int sum = 0;
        for(int i = 1;i<sLength;i++){
            if(alphabet == s[i]){
                streak++;
            }else{
                sum += ((streak) * (streak + 1)) / 2;
                alphabet = s[i];
                streak = 1;
            }
        }
        
        sum += (((streak) * (streak + 1)) / 2);
        return sum;
    }
};