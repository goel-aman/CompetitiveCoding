#include<bits/stdc++.h>
using namespace std;

// 220. Contains Duplicate III
// Given an integer array nums and two integers k and t, return 
// true if there are two distinct indices i and j in the array 
// such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

// Example 1:
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true

// Example 2:
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true

// Example 3:
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false

// Constraints:
// 0 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 104
// 0 <= t <= 231 - 1

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int numsLength = nums.size();
        map<long,int> m;
        int l = 0,r = 0;
        while(r < numsLength){

            if(r > k){
                if(m[nums[l]] == 1){
                    m.erase(nums[l]);
                }else{
                    m[nums[l]]--;
                }
                l++;
            }

            long a = nums[r] - t;
            long b = nums[r] + t;

            auto it = m.lower_bound(a);

            if(it->first>=min(a,b) && it->first <=max(a,b)){
                return true;
            }

            m[nums[r]]++;
            r++;
        }
        return false;
    }
};