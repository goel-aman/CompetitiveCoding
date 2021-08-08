#include<bits/stdc++.h>
using namespace std;

// 1003. Check If Word Is Valid After Substitutions
// Given a string s, determine if it is valid.
// A string s is valid if, starting with an empty string
//  t = "", you can transform t into s after performing the
//  following operation any number of times:

// Insert string "abc" into any position in t. More formally,
//  t becomes tleft + "abc" + tright, where t == tleft + tright.
//  Note that tleft and tright may be empty.
// Return true if s is a valid string, otherwise, return false.

// Example 1:
// Input: s = "aabcbc"
// Output: true
// Explanation:
// "" -> "abc" -> "aabcbc"
// Thus, "aabcbc" is valid.

// Example 2:
// Input: s = "abcabcababcc"
// Output: true
// Explanation:
// "" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
// Thus, "abcabcababcc" is valid.

// Example 3:
// Input: s = "abccba"
// Output: false
// Explanation: It is impossible to get "abccba"
//  using the operation.

// Example 4:
// Input: s = "cababc"
// Output: false
// Explanation: It is impossible to get "cababc" using the operation.
 

// Constraints:
// 1 <= s.length <= 2 * 104
// s consists of letters 'a', 'b', and 'c'


class Solution {
public:
    bool isValid(string s) {
        int sLength = s.length();

        int tempACount = 0;
        int tempBCount = 0;
        int tempCCount = 0;
        int Count = 0;
        for(int i=0;i<sLength;i++){
            if( i <= sLength - 3 && s.substr(i,3) == "abc"){
                Count++;
            }
            if(s[i] == 'a'){
                tempACount++;
            }

            if(s[i] == 'b'){
                tempBCount++;
                if(tempBCount > tempACount){
                    return false;
                }
            }

            if(s[i] == 'c'){
                tempCCount++;
                if(tempCCount > tempBCount || tempCCount > tempACount){
                    return false;
                }
            }
        }      

        if(Count == 0 || tempACount != tempBCount || tempACount != tempCCount || tempBCount != tempCCount){
            return false;
        }
        string tempString = s;
        while(tempString.length() > 0){
            int currentLength = tempString.length();

            for(int i=0;i<=currentLength - 3;i++){
                if(tempString.substr(i,3) == "abc"){
                    tempString = tempString.substr(0,i) + tempString.substr(i + 3);
                    break;
                }
            }
            if(tempString.length() == currentLength){
                return false;
            }
        }
        
        return true;
    }
};