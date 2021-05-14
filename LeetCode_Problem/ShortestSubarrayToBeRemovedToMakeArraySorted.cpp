#include<bits/stdc++.h>
using namespace std;

// 1574. Shortest Subarray to be Removed to Make Array Sorted

// Given an integer array arr, remove a subarray (can be empty) from arr
//  such that the remaining elements in arr are non-decreasing.
// A subarray is a contiguous subsequence of the array.
// Return the length of the shortest subarray to remove.

// Example 1:
// Input: arr = [1,2,3,10,4,2,3,5]
// Output: 3
// Explanation: The shortest subarray we can remove is [10,4,2] of length 3. 
// The remaining elements after that will be [1,2,3,3,5] which are sorted.
// Another correct solution is to remove the subarray [3,10,4].

// Example 2:
// Input: arr = [5,4,3,2,1]
// Output: 4
// Explanation: Since the array is strictly decreasing, we can only keep a single
//  element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

// Example 3:
// Input: arr = [1,2,3]
// Output: 0
// Explanation: The array is already non-decreasing. We do not need to remove any elements.

// Example 4:
// Input: arr = [1]
// Output: 0
 
// Constraints:
// 1 <= arr.length <= 10^5
// 0 <= arr[i] <= 10^9


class Solution {
    int arrLength;
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        arrLength = arr.size();
        int ans = arrLength;
        int right = 1;
        int left = 1;
        
        for(int i=1;i<arrLength;i++){
            if(arr[i] >= arr[i - 1]){
                left++;continue;
            }
            break;
        }
        ans = min(ans,arrLength - left);
        for(int i=arrLength - 2;i>=0;i--){
            if(arr[i] <= arr[i + 1]){
                right++;continue;
            }
            break;
        }   
        
        ans = min(ans,arrLength - right);
        if(ans == 0){
            return 0;
        }
        int start = left - 1;
        int end = arrLength - 1;
        while(start >= 0 && end >= arrLength - right){
            if(arr[start] <= arr[end]){
                ans = min(ans,end - start - 1);
                if(ans == -1){
                    ans = 0;
                }
                end--;
                continue;
            }

            if(arr[start] > arr[end]){
                start--;
                continue;
            }
        }
        if(ans == arrLength){
            return arrLength - 1;
        }
        return ans;
    }
};