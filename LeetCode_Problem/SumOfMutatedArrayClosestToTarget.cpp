#include<bits/stdc++.h>
using namespace std;

// 1300. Sum of Mutated Array Closest to Target

// Given an integer array arr and a target value target, return the integer 
// value such that when we change all the integers larger than value in the 
// given array to be equal to value, the sum of the array gets as close as 
// possible (in absolute difference) to target.

// In case of a tie, return the minimum such integer.
// Notice that the answer is not neccesarilly a number from arr.

// Example 1:
// Input: arr = [4,9,3], target = 10
// Output: 3
// Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.

// Example 2:
// Input: arr = [2,3,5], target = 10
// Output: 5

// Example 3:
// Input: arr = [60864,25176,27249,21296,20204], target = 56803
// Output: 11361
 
// Constraints:
// 1 <= arr.length <= 104
// 1 <= arr[i], target <= 105

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int arrLength = arr.size();
        int maxValue = INT_MIN;
        int arrSum = 0;
        for(int i=0;i<arrLength;i++){
            arrSum += arr[i];
            maxValue = max(maxValue,arr[i]);
        }
        if(arrSum <= target){
            return maxValue;
        }


        int start = 0, end = maxValue;
        int diff = INT_MAX;
        int ans = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            int tempSum = 0;
            for(int i=0;i<arrLength;i++){
                if(arr[i] > mid){
                    tempSum += mid;
                }else{
                    tempSum += arr[i]; 
                }
            }

            if(tempSum == target){
                ans = mid;
                diff = 0;
                break;
            }

            if(tempSum > target){
                if(tempSum - target < diff){
                    diff = tempSum - target;
                    ans = mid;
                }
                if(tempSum - target == diff){
                    diff = tempSum - target;
                    ans = min(ans,mid);
                }
                end = mid - 1;
                continue;
            }

            if(tempSum < target){
                if(target - tempSum < diff){
                    diff = target - tempSum;
                    ans = mid;
                }
                if(target - tempSum == diff){
                    diff = target - tempSum;
                    ans = min(ans,mid);
                }
                start = mid + 1;
                continue;
            }
        }
        return ans;
    }
};