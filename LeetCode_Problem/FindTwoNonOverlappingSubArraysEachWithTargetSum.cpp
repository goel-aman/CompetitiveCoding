#include<bits/stdc++.h>
using namespace std;

// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// Given an array of integers arr and an integer target.
// You have to find two non-overlapping sub-arrays of arr 
// each with a sum equal target. There can be multiple 
// answers so you have to find an answer where the sum of 
// the lengths of the two sub-arrays is minimum.

// Return the minimum sum of the lengths of the two required
//  sub-arrays, or return -1 if you cannot find such two 
// sub-arrays.

// Example 1:
// Input: arr = [3,2,2,4,3], target = 3
// Output: 2
// Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). 
// The sum of their lengths is 2.

// Example 2:
// Input: arr = [7,3,4,7], target = 7
// Output: 2
// Explanation: Although we have three non-overlapping sub-arrays of 
// sum = 7 ([7], [3,4] and [7]), but we will choose the first and third
//  sub-arrays as the sum of their lengths is 2.

// Example 3:
// Input: arr = [4,3,2,6,2,3,4], target = 6
// Output: -1
// Explanation: We have only one sub-array of sum = 6.

// Example 4:
// Input: arr = [5,5,4,4,5], target = 3
// Output: -1
// Explanation: We cannot find a sub-array of sum = 3.

// Example 5:
// Input: arr = [3,1,1,1,5,1,2,1], target = 3
// Output: 3
// Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an answer 
// because they overlap.
 
// Constraints:
// 1 <= arr.length <= 105
// 1 <= arr[i] <= 1000
// 1 <= target <= 108

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int arrLength = arr.size();
        vector<int> prefix(arrLength + 1,INT_MAX);
        vector<int> suffix(arrLength + 1,INT_MAX);
        int sum = 0;
        unordered_map<int,int> um;
        um[0] = 0;
        for(int i=0;i<arrLength;i++){
            sum += arr[i];
            int current = INT_MAX;
            if(um.count(sum - target) > 0){
                if(sum - target == 0){
                    current = i - um[sum - target] + 1;    
                }else{
                    current = i - um[sum - target];
                }
                
            }
            if(i == 0){
                prefix[i] = current;
            }else{
                prefix[i] = min(prefix[i - 1],current);
            }
            um[sum] = i;
        }
        unordered_map<int,int> um2;
        um2[0] = arrLength - 1;
        sum = 0;
        for(int i=arrLength - 1;i>=0;i--){
            sum += arr[i];
            int current = INT_MAX;
            
            if(um2.count(sum - target)> 0){
                if(sum - target == 0){
                    current = abs(i - um2[sum - target]) + 1;    
                }else{
                    current = abs(i - um2[sum - target]);
                }
            }
            if(i == arrLength - 1){
                suffix[i] = current;
            }else{
                suffix[i] = min(suffix[i + 1],current);
            }
            um2[sum] = i;
        }
        
        int finalValue = INT_MAX;
        for(int j=0;j<arrLength - 1;j++){
            if(prefix[j] != INT_MAX && suffix[j + 1] != INT_MAX){
                finalValue = min(finalValue,prefix[j] + suffix[j + 1]);
            }
        }

        return (finalValue == INT_MAX) ? -1 : finalValue;
    }
};