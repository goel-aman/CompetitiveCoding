#include<bits/stdc++.h>
using namespace std;

// 1593. Split a String Into the Max Number of Unique Substrings

// Given a string s, return the maximum number of unique
//  substrings that the given string can be split into.
// You can split string s into any list of non-empty substrings, 
// where the concatenation of the substrings forms the original string. 
// However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.

// Example 1:
// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc'].
//  Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have
//  'a' and 'b' multiple times.

// Example 2:
// Input: s = "aba"
// Output: 2
// Explanation: One way to split maximally is ['a', 'ba'].

// Example 3:
// Input: s = "aa"
// Output: 1
// Explanation: It is impossible to split the string any further.
 
// Constraints:
// 1 <= s.length <= 16
// s contains only lower case English letters.

class Solution {
public:
    int unique(string s,unordered_map<string,bool>& visited){
        int sLength = s.length();
        if(sLength == 0){
            return 0;
        }
        int ans = INT_MIN;
        for(int i=1;i<=sLength;i++){
            string temp = s.substr(0,i);
            string leftOut = s.substr(i);
            if(visited.count(temp)){
                if(visited[temp] == false){
                    visited[temp] = true;
                    ans = max(ans, 1 + unique(leftOut,visited));
                    visited[temp] = false;
                }
            }
            else{
                visited[temp] = true;
                ans = max(ans,1 + unique(leftOut,visited));
                visited[temp] = false;
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,bool> visited;
        return unique(s,visited);
    }
}; 