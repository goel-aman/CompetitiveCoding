#include<bits/stdc++.h>
using namespace std;

// 1119. Remove Vowels from a String'

// Given a string s, remove the vowels
//  'a', 'e', 'i', 'o', and 'u' from it, 
// and return the new string.

// Example 1:
// Input: s = "leetcodeisacommunityforcoders"
// Output: "ltcdscmmntyfrcdrs"

// Example 2:
// Input: s = "aeiou"
// Output: ""
 
// Constraints:
// 1 <= s.length <= 1000
// s consists of only lowercase English letters.

class Solution {
public:
    string removeVowels(string s) {
        string ans = "";
        int sLength = s.length();
        
        for(int i=0;i<sLength;i++){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
                ans += s[i];
            }
        }
        return ans;
    }
};