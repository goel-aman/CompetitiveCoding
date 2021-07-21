#include<bits/stdc++.h>
using namespace std;

// 647. Palindromic Substrings
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic
// strings: "a", "a", "a", "aa", "aa", "aaa".
 
// Constraints:
// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:
    bool isPalindrome(string s){
        string temp = s;
        reverse(temp.begin(),temp.end());
        if(s == temp){
            return true;
        }
        return false;
    }

    int countSubstrings(string s) {
        int sLength = s.length();
        if(sLength == 0){
            return 0;
        }
        if(sLength == 1){
            return 1;
        }
        int ans = 0;
        for(int i=1;i<=sLength;i++){
            ans += isPalindrome(s.substr(0,i));
        }
        ans += countSubstrings(s.substr(1));
        return ans;
    }
};
