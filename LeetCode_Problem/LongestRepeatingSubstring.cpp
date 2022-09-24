#include<bits/stdc++.h>
using namespace std;

// 1062. Longest Repeating Substring
// Given a string s, return the length of the longest 
// repeating substrings. If no repeating substring
//  exists, return 0.

// Example 1:
// Input: s = "abcd"
// Output: 0
// Explanation: There is no repeating substring.

// Example 2:
// Input: s = "abbaba"
// Output: 2
// Explanation: The longest repeating substrings
//  are "ab" and "ba", each of which occurs twice.

// Example 3:
// Input: s = "aabcaabdaab"
// Output: 3
// Explanation: The longest repeating 
// substring is "aab", which occurs 3 times.
 
// Constraints:
// 1 <= s.length <= 2000
// s consists of lowercase English letters.

class Solution {
    int sLength;
public:
    bool check(string s,int length){
        unordered_set<string> store;

        for(int i=0;i<=sLength - length;i++){
            if(store.count(s.substr(i,length)) > 0){
                return true;
            }else{
                store.insert(s.substr(i,length));
            }
        }
        return false;
    }

    int longestRepeatingSubstring(string s) {
        sLength = s.length();
        int ans = 0;
        int start = 1, end = sLength - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(check(s,mid)){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};