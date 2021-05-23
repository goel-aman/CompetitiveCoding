#include<bits/stdc++.h>
using namespace std;

// 467. Unique Substrings in Wraparound String

// We define the string s to be the infinite wraparound string 
// of "abcdefghijklmnopqrstuvwxyz", so s will look like this:

// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// Given a string p, return the number of unique non-empty substrings
//  of p are present in s.

// Example 1:
// Input: p = "a"
// Output: 1
// Explanation: Only the substring "a" of p is in s.

// Example 2:
// Input: p = "cac"
// Output: 2
// Explanation: There are two substrings ("a", "c") of p in s.

// Example 3:
// Input: p = "zab"
// Output: 6
// Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of p in s.
 
// Constraints:
// 1 <= p.length <= 105
// p consists of lowercase English letters.

class Solution {
    unordered_set<string> s;
public:
    int findSubstringInWraproundString(string p) {
        int pLength = p.length();
        vector<int> vec(26,0);
        int maxLength = 0;
        for(int i=0;i<pLength;i++){
            if(i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25 )){
                maxLength++;
            }else{
                maxLength = 1;
            }
            vec[p[i] - 'a'] =  max(vec[p[i] - 'a'],maxLength);
        }
        int ans = 0;
        for(auto element : vec){
            ans += element;
        }
        return ans;
    }
};