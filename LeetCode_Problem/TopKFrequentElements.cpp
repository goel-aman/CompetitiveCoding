#include<bits/stdc++.h>
using namespace std;

// 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return
//  the k most frequent elements. You may return the 
// answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
 
// Constraints:
// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements
//  in the array].
// It is guaranteed that the answer is unique.
 
// Follow up: Your algorithm's time complexity must be better
//  than O(n log n), where n is the array's size.

class element
{
    public:
    int freq;
    int num;
};

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // can also be done using a heap of size k.
        unordered_map<int,int> um;
        int numsLength = nums.size();
        for(int i=0;i<numsLength;i++){
            um[nums[i]]++;
        }   

        vector<pair<int,int>> vec;
        for(auto var : um){
            vec.push_back({var.second,var.first});
        }
        sort(vec.begin(),vec.end());
        int kk = 0;
        vector<int> ans;
        for(int i = vec.size() - 1;i>=0 && kk < k;i--){
            ans.push_back(vec[i].second);
            kk++;
        }
        return ans;
    }
};