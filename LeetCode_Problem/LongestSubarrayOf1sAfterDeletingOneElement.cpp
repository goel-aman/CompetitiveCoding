#include<bits/stdc++.h>
using namespace std;

// 1493. Longest Subarray of 1's After Deleting One Element
// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only
//  1's in the resulting array.
// Return 0 if there is no such subarray.

// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] 
// contains 3 numbers with value of 1's.

// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4,
//  [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

// Example 4:
// Input: nums = [1,1,0,0,1,1,1,0,1]
// Output: 4

// Example 5:
// Input: nums = [0,0,0]
// Output: 0
 
// Constraints:
// 1 <= nums.length <= 10^5
// nums[i] is either 0 or 1.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> temp;
        int onesCount = 0;
        int zeroCount = 0;
        int ans = 0;
        int i=0;

        for(;i<numsLength;i++){
            if(nums[i] == 0){
                continue;
            }
            break;
        }

        for(;i<numsLength;i++){
            if(nums[i] == 1){
                onesCount++;
            }else{
                if(i + 1 < numsLength && nums[i + 1] == 0){
                    if(onesCount != 0){
                        temp.push_back(onesCount);
                        onesCount = 0;
                        temp.push_back(-1);
                    }
                }else{
                    if(onesCount != 0){
                        temp.push_back(onesCount);
                        onesCount = 0;
                    }
                }
                onesCount = 0;
            }
        }
        if(onesCount != 0){
            temp.push_back(onesCount);
        }
        // cout<<"hello world"<<endl;
        for(int j=0;j<temp.size();j++){
            ans = max(ans,temp[j]);
            if(j + 1 < temp.size() && temp[j] != -1 && temp[j +1] != -1){
                ans = max(ans,temp[j] + temp[j + 1]);
            }
        }
        if(ans == numsLength){
            return ans - 1;
        }
        return ans;
    }
};