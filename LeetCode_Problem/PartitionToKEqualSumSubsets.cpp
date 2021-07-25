#include<bits/stdc++.h>
using namespace std;

// 698. Partition to K Equal Sum Subsets
// Given an integer array nums and an integer k,
//  return true if it is possible to divide this 
// array into k non-empty subsets whose sums are
//  all equal.

// Example 1:
// Input: nums = [4,3,2,3,5,2,1], k = 4
// Output: true
// Explanation: It's possible to divide it into 4
//  subsets (5), (1, 4), (2,3), (2,3) with equal sums.

// Example 2:
// Input: nums = [1,2,3,4], k = 3
// Output: false
 
// Constraints:
// 1 <= k <= nums.length <= 16
// 1 <= nums[i] <= 104
// The frequency of each element is in the range [1, 4].




class Solution {
    int numsLength;
public:

    bool Partition(vector<int>& nums,vector<int>& visited,int index,int k,int currentSum,int target){
        if(k == 0){
            return true;
        }

        if(currentSum == target){
            return Partition(nums,visited,0,k - 1,0,target);
        }

        for(int i=index;i<numsLength;i++){
            if(currentSum + nums[i] <= target && visited[i] == 0){
                visited[i] = true;
                bool ans = Partition(nums,visited,i,k,currentSum + nums[i],target);
                visited[i] = false;
                if(ans == true){
                    return true;
                }
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        numsLength = nums.size();
        int sum = 0;
        for(int i=0;i<numsLength;i++){
            sum += nums[i];
        }
        if(sum%k != 0){
            return false;
        }
        int target = (sum / k);
        vector<int> visited(numsLength,0);
        bool ans = Partition(nums,visited,0,k,0,target);
        return ans;
    }
}; 