#include<bits/stdc++.h>
using namespace std;

// 801. Minimum Swaps To Make Sequences Increasing
// You are given two integer arrays of the same length 
// nums1 and nums2. In one operation, you are allowed 
// to swap nums1[i] with nums2[i].
// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4],
//  you can swap the element at i = 3 to obtain nums1 = [1,2,3,4]
//  and nums2 = [5,6,7,8].
// Return the minimum number of needed operations to make nums1
//  and nums2 strictly increasing. The test cases are generated 
// so that the given input always makes it possible.

// An array arr is strictly increasing if and only if 
// arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

// Example 1:
// Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
// Output: 1
// Explanation: 
// Swap nums1[3] and nums2[3]. Then the sequences are:
// nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
// which are both strictly increasing.

// Example 2:
// Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
// Output: 1
 
// Constraints:
// 2 <= nums1.length <= 105
// nums2.length == nums1.length
// 0 <= nums1[i], nums2[i] <= 2 * 105

class Solution {
    int nums1Length;
    int nums2Length;
public:
    int solve(vector<int> nums1,vector<int> nums2,int index1,int swappingNeeded){
        if(index1 == nums2Length - 1){
            if(swappingNeeded){
                int temp = nums1[index1];
                nums1[index1] = nums2[index1];
                nums2[index1] = temp;
                if(nums1[index1] > nums1[index1 - 1] && nums2[index1] > nums2[index1 - 1]){
                    return 1;
                }
                return INT_MAX;
            }
            return 0;
        }

        
        if(swappingNeeded){
            int temp = nums1[index1];
            nums1[index1] = nums2[index1];
            nums2[index1] = temp;
            if(nums1[index1] > nums1[index1 - 1] && nums2[index1] > nums2[index1 - 1]){
                return 1 + solve(nums1,nums2,index1,0);
            }
            return INT_MAX;
        }


        if(nums1[index1] < nums1[index1 + 1] && nums2[index1] < nums2[index1 + 1]){
            return solve(nums1,nums2,index1 + 1,0);
        }

        // first case swap it right now or else do it later.
        int value1 = solve(nums1,nums2,index1 + 1,1);

        
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1Length = nums1.size();
        nums2Length = nums2.size();
        int swaps = 0;
        int swappingNeeded = 0;
        int i = 0, j = 0;

    }
};