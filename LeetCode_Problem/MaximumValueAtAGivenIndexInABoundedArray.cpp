#include<bits/stdc++.h>
using namespace std;

// 1802. Maximum Value at a Given Index in a Bounded Array

// You are given three positive integers: n, index, and maxSum. You want to 
// construct an array nums (0-indexed) that satisfies the following conditions:

// nums.length == n
// nums[i] is a positive integer where 0 <= i < n.
// abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
// The sum of all the elements of nums does not exceed maxSum.
// nums[index] is maximized.
// Return nums[index] of the constructed array.

// Note that abs(x) equals x if x >= 0, and -x otherwise.

// Example 1:
// Input: n = 4, index = 2,  maxSum = 6
// Output: 2
// Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
// There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

// Example 2:
// Input: n = 6, index = 1,  maxSum = 10
// Output: 3
 
// Constraints:
// 1 <= n <= maxSum <= 109
// 0 <= index < n
class Solution {
public:
    long getValue(int n,int index,int mid){
        long res = 0;
        long a = max((mid - index),0);
        long b = mid;
        
        res = res + ((b + a) *(1 + b - a))/2;
        b = mid;
        a = max((mid - ((n - 1)-index)),0);
        res = res + ((b + a)*(1 + b - a))/2;
        return res - mid;
    }

    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int start = 0,end = maxSum;
        int answer = 0;
        while(start <= end){
            int mid = (start + end) /2;
            long val = getValue(n,index,mid);
            if(val <= maxSum){
                answer = max(answer,mid);
                start = mid + 1;
                continue;
            }else{
                end = mid - 1;
            }
        }
        return answer + 1; 
    }
};