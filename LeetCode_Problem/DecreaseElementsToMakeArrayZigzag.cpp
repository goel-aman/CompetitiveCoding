#include<bits/stdc++.h>
using namespace std;

// 1144. Decrease Elements To Make Array Zigzag

// Given an array nums of integers, a move consists of 
// choosing any element and decreasing it by 1.

// An array A is a zigzag array if either:
// Every even-indexed element is greater than adjacent 
// elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
// OR, every odd-indexed element is greater than adjacent
//  elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
// Return the minimum number of moves to transform the
//  given array nums into a zigzag array.

// Example 1:
// Input: nums = [1,2,3]
// Output: 2
// Explanation: We can decrease 2 to 0 or 3 to 1.

// Example 2:
// Input: nums = [9,6,1,6,2]
// Output: 4
 
// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int numsLength = nums.size();
        int value1 = 0;
        int value2 = 0;
        for(int i=0;i<numsLength;i+=2){
            int value = INT_MAX;
            if(i - 1 >= 0){
                value = min(value,nums[i - 1]);
            }

            if(i + 1 < numsLength){
                value = min(value,nums[i + 1]);
            }
            value -= 1;
            if(nums[i] <= value){
                continue;
            }

            value1 += (nums[i] - value);
        }
        // cout<<"value1 is ; "<<value1<<endl;
        for(int i=1;i<numsLength;i+=2)
        {
            int value = INT_MAX;
            if(i - 1 >= 0){
                value = min(value,nums[i - 1]);
            }

            if(i + 1 < numsLength){
                value = min(value,nums[i + 1]);
            }

            value -= 1;
            if(nums[i] <= value){
                continue;
            }

            value2 += (nums[i] - value);
        }
        return min(value1,value2);
    }
};