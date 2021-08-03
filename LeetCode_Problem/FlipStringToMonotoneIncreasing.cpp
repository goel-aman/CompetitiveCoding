#include<bits/stdc++.h>
using namespace std;

// 926. Flip String to Monotone Increasing
// A binary string is monotone increasing if it consists of 
// some number of 0's (possibly none), followed by some number
//  of 1's (also possibly none).
// You are given a binary string s. You can flip s[i] changing
//  it from 0 to 1 or from 1 to 0.
// Return the minimum number of flips to make s monotone increasing.

// Example 1:
// Input: s = "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.

// Example 2:
// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.

// Example 3:
// Input: s = "00011000"
// Output: 2
// Explanation: We flip to get 00000000.
 
// Constraints:
// 1 <= s.length <= 105
// s[i] is either '0' or '1'.

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int sLength = s.length();
        vector<pair<int,int>> prefix(sLength,{0,0});
        
        // first is zero, second is one.
        for(int i=0;i<sLength;i++){
            if(i == 0){
                if(s[i] == '0'){
                    prefix[i].first = 1;
                    prefix[i].second = 0;
                }else{
                    prefix[i].first = 0;
                    prefix[i].second = 1;
                }
                continue;
            }
            if(s[i] == '0'){
                prefix[i].first = prefix[i - 1].first + 1;
                prefix[i].second = prefix[i - 1].second;
            }

            if(s[i] == '1'){
                prefix[i].second = prefix[i - 1].second + 1;
                prefix[i].first = prefix[i - 1].first;
            }
        }

        vector<pair<int,int>> suffix(sLength,{0,0});
        for(int i=sLength - 1;i>=0;i--){
            if(i == sLength - 1){
                if(s[i] == '0'){
                    suffix[i].first = 1;
                    suffix[i].second = 0;
                }else{
                    suffix[i].first = 0;
                    suffix[i].second = 1;
                }
                continue;
            }
            if(s[i] == '0'){
                suffix[i].first = suffix[i + 1].first + 1;
                suffix[i].second = suffix[i + 1].second;
            }

            if(s[i] == '1'){
                suffix[i].second = suffix[i + 1].second + 1;
                suffix[i].first = suffix[i + 1].first;
            }
        }

        int ans = INT_MAX;
         
        int allZero = suffix[0].second;
        
        ans = min(ans,allZero);
        int allOne = suffix[0].first;
        ans = min(ans,allOne);

        for(int i=0;i<sLength - 1;i++){
            int val = prefix[i].second + suffix[i + 1].first;
            ans = min(ans,val);
        }
        return ans;
    }
};