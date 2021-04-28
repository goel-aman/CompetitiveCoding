#include<bits/stdc++.h>
using namespace std;

// 384. Shuffle an Array

// Given an integer array nums, design an algorithm to randomly shuffle the array.

// Implement the Solution class:

// Solution(int[] nums) Initializes the object with the integer array nums.
// int[] reset() Resets the array to its original configuration and returns it.
// int[] shuffle() Returns a random shuffling of the array.
 

// Example 1:

// Input
// ["Solution", "shuffle", "reset", "shuffle"]
// [[[1, 2, 3]], [], [], []]
// Output
// [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

// Explanation
// Solution solution = new Solution([1, 2, 3]);
// solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
// solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
// solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

// Constraints:

// 1 <= nums.length <= 200
// -106 <= nums[i] <= 106
// All the elements of nums are unique.
// At most 5 * 104 calls will be made to reset and shuffle


class Solution {
    vector<int> initial;
    int numsLength;
public:
    Solution(vector<int>& nums) {
        numsLength = nums.size();
        for(int i=0;i<numsLength;i++){
            initial.push_back(nums[i]);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return initial;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans;
        unordered_set<int> s;
        while(s.size() != numsLength){
            int val =  rand() % numsLength;
            if(s.count(val) > 0)
            {
                continue;
            }else{
                s.insert(val);
                ans.push_back(initial[val]);
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */