#include<bits/stdc++.h>
using namespace std;

// 395. Longest Substring with At Least K Repeating Characters
// Given a string s and an integer k, return the length of the
//  longest substring of s such that the frequency of each character
//  in this substring is greater than or equal to k.

// Example 1:
// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as
//  'a' is repeated 3 times.

// Example 2:
// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as
//  'a' is repeated 2 times and 'b' is repeated 3 times.
 
// Constraints:
// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105


class Solution {
public:
    int longSubString(string s,int k){
        // cout<<"value of s is : "<<s<<endl;
        int sLength = s.length();
        if(sLength == 0 || k > sLength){
            // cout<<"answer is : "<<0<<endl;
            return 0;
        }

        unordered_map<char,int> um;
        for(int i=0;i<sLength;i++){
            um[s[i]]++;
        }

        int splitPoint = -1;

        for(int i=0;i<sLength;i++){
            if(um[s[i]] < k){
                splitPoint = i;
                break;
            }
        }
        
        if(splitPoint == -1){
            // cout<<"value of ans is : "<<sLength<<endl;
            return sLength;          
        }

        int val = max(longSubString(s.substr(0,splitPoint),k),longSubString(s.substr(splitPoint + 1),k));
        // cout<<"valueof ans is : "<<val<<endl;
        return val;
    }

    int longestSubstring(string s, int k) {
        return longSubString(s,k);
    }
};