// 125. Valid Palindrome

// Given a string s, determine if it is a palindrome, 
// considering only alphanumeric characters and ignoring cases.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Constraints:
// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int sLength = s.length();
        if(sLength == 0){
            return true;
        }
        
        string news = "";
        for(int i=0;i<sLength;i++){
            if(isalnum(s[i])){
                news += tolower(s[i]);
            }
        }
        
        string reversed = news;
        reverse(news.begin(),news.end());
        for(int i=0;i<news.length();i++){
            if(reversed[i] != news[i]){
                return false;
            }
        }
        return true;
    }
};