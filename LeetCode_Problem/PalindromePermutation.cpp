#include<bits/stdc++.h>
using namespace std;

// 266. Palindrome Permutation
// Given a string s, return true if a permutation of the 
// string could form a palindrome.

// Example 1:
// Input: s = "code"
// Output: false

// Example 2:
// Input: s = "aab"
// Output: true

// Example 3:
// Input: s = "carerac"
// Output: true

// Constraints:
// 1 <= s.length <= 5000
// s consists of only lowercase English letters.

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int sLength = s.length();
        if(sLength == 0 || sLength == 1){
            return true;
        }
        
        unordered_map<char,int> count;
        for(int i=0;i<sLength;i++){
            count[s[i]]++;
        }
        int totalOdd = 0;
        for(auto var : count){
            if(var.second%2 != 0){
                totalOdd++;
            }
        }
        
        if(totalOdd > 1){
            return false;
        }
        return true;
    }
};