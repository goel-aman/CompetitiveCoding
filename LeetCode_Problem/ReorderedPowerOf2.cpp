#include<bits/stdc++.h>
using namespace std;

// 869. Reordered Power of 2
// You are given an integer n. We reorder the digits in any
// order (including the original order) such that the leading
//  digit is not zero.
// Return true if and only if we can do this so that the 
// resulting number is a power of two.

// Example 1:
// Input: n = 1
// Output: true

// Example 2:
// Input: n = 10
// Output: false

// Example 3:
// Input: n = 16
// Output: true

// Example 4:
// Input: n = 24
// Output: false

// Example 5:
// Input: n = 46
// Output: true

// Constraints:
// 1 <= n <= 109

class Solution {
    unordered_map<string,bool> um;
public:
    Solution(){
        long long value =1;
        um["1"] = true;
        for(int i = 1;i<=30;i++){
            value *= 2;
            string temp = to_string(value);
            sort(temp.begin(),temp.end());
            um[temp] = true;
        }
    }
    bool reorderedPowerOf2(int n) {
        string inString = to_string(n);
        sort(inString.begin(),inString.end());
        if(um.count(inString)){
            return true;
        }
        return false;
    }
};