// Non-negative Integers without Consecutive Ones
// Given a positive integer n, find the number of non-negative integers less than or equal to n, 
// whose binary representations do NOT contain consecutive ones.

// Example 1:
// Input: 5
// Output: 5
// Explanation: 
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
// Note: 1 <= n <= 109

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findIntegers(int num) {
        int * f = new int[33];
        int prevzero = 1;
        int prevone = 1;
        f[0] = 1;
        f[1] = 2;
        for(int i=2;i<32;i++){
            int val1 = prevzero;
            int val2 = prevone;
            f[i] = (prevzero + prevone) + prevzero;
            prevzero = val1 + val2;
            prevone = val1;       
        }
        int ans = 0, k = 30, pre_bit = 0;
        while(k >=0){
            if(num&(1<<k)){
                ans += f[k];
                if(pre_bit) {
                    return ans;
                }
                pre_bit = 1;
            }
            else{
                pre_bit = 0;
            }
            k--;
        }
        return ans + 1;
    }
};