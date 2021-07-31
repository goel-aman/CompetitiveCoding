#include<bits/stdc++.h>
using namespace std;

// 1186. Maximum Subarray Sum with One Deletion
// Given an array of integers, return the maximum sum for 
// a non-empty subarray (contiguous elements) with at most
//  one element deletion. In other words, you want to choose
//  a subarray and optionally delete one element from it so
//  that there is still at least one element left and the 
// sum of the remaining elements is maximum possible.

// Note that the subarray needs to be non-empty after 
// deleting one element.

// Example 1:
// Input: arr = [1,-2,0,3]
// Output: 4
// Explanation: Because we can choose [1, -2, 0, 3] and 
// drop -2, thus the subarray [1, 0, 3] becomes the
//  maximum value.

// Example 2:
// Input: arr = [1,-2,-2,3]
// Output: 3
// Explanation: We just choose [3] and it's the maximum sum.

// Example 3:
// Input: arr = [-1,-1,-1,-1]
// Output: -1
// Explanation: The final subarray needs to be non-empty. You
//  can't choose [-1] and delete -1 from it, then get an empty
//  subarray to make the sum equals to 0.
 
// Constraints:
// 1 <= arr.length <= 105
// -104 <= arr[i] <= 104


class Solution {
    int arrLength;
public:
    int maximumSum(vector<int>& arr) {
        
        arrLength = arr.size();
        if(arrLength == 1){
            return arr[0];
        }
        vector<int> left(arrLength,0);
        vector<int> right(arrLength,0);

        left[0] = arr[0];

        for(int i=1;i<arrLength;i++){
            left[i] = max(left[i - 1] + arr[i],arr[i]);
        }      

        right[arrLength - 1] = arr[arrLength - 1];
        for(int i=arrLength-2;i>=0;i--){
            right[i] = max(right[i + 1] + arr[i],arr[i]);
        }
        int ans = INT_MIN;
        for(int i=0;i<arrLength;i++){
            if(i == 0){
                ans = max(ans,right[i + 1]);
                continue;
            }

            if(i == arrLength - 1){
                ans = max(ans,left[arrLength - 2]);
                continue;
            }

            ans = max({ans,left[i - 1] + right[i + 1],left[i - 1],right[i + 1]});
        }
        if(arrLength >= 2){
            ans = max(ans,arr[0]);
            ans = max(ans,arr[arrLength - 1]);
        }
        ans = max(left[arrLength - 1],ans);
        return ans;
    }
};