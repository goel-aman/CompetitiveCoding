#include<bits/stdc++.h>
using namespace std;

// 89. Gray Code

// The gray code is a binary numeral system where two successive 
// values differ in only one bit.
// Given an integer n representing the total number of bits in the
//  code, return any sequence of gray code.
// A gray code sequence must begin with 0.

// Example 1:
// Input: n = 2
// Output: [0,1,3,2]
// Explanation:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// [0,2,3,1] is also a valid gray code sequence.
// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1

// Example 2:
// Input: n = 1
// Output: [0,1]
 
// Constraints:
// 1 <= n <= 16

class Solution {
    int power[17];
public:
    Solution(){
        power[0] = 1;
        for(int i=1;i<17;i++){
            power[i] = power[i - 1] * 2;
        }
    }

    vector<string> Code(int n){
        vector<string> ans;
        if(n == 1){
            ans.push_back("0");
            ans.push_back("1");
            return ans;
        }
        
        vector<string> temp = Code(n - 1);
        for(int i=0;i<temp.size();i++){
            string tempValue = "0" + temp[i];
            ans.push_back(tempValue);
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            string tempValue = "1" + temp[i];
            ans.push_back(tempValue);
        }

        return ans;
    }
    
    int calculate(string s){
        int sLength = s.length();
        int p = 0;
        int value = 0;
        for(int i=sLength - 1;i>=0;i--){
            if(s[i] == '1'){
                value += power[p];
            }
            p++;
        } 
        return value;
    }

    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<string> val = Code(n);
        for(int i=0;i<val.size();i++){
            ans.push_back(calculate(val[i]));
        }      
        return ans;
    }
};