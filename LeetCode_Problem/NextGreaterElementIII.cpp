#include<bits/stdc++.h>
using namespace std;

// 556. Next Greater Element III
// Given a positive integer n, find the smallest integer which has
//  exactly the same digits existing in the integer n and is greater
//  in value than n. If no such positive integer exists, return -1.
// Note that the returned integer should fit in 32-bit integer, if 
// there is a valid answer but it does not fit in 32-bit integer,
//  return -1.

// Example 1:
// Input: n = 12
// Output: 21

// Example 2:
// Input: n = 21
// Output: -1
 
// Constraints:
// 1 <= n <= 231 - 1

class Solution {
public:
    int nextGreaterElement(int n) {
        long number = n;
        int prevNum = -1;
        vector<int> num(10,0);
        int currentNum = -1;
        while(number > 0){
            currentNum = number%10;
            number /= 10;
            num[currentNum]++;
            if(currentNum < prevNum){
                int start = currentNum + 1;
                while(num[start] == 0){
                    start++;
                }
                num[start]--;
                number = number * 10 + start;
                start = 0;
                while(start <= 9){
                    for(int i=0;i<num[start];i++){
                        number = number* 10 + start;
                    }
                    start++;
                }
                if(number > INT_MAX){
                    return -1;
                }
                return number;
            }
            
            prevNum = currentNum;
        }
        return -1;
    }
};