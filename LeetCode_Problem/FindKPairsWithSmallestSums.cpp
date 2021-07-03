#include<bits/stdc++.h>
using namespace std;

// 373. Find K Pairs with Smallest Sums
// You are given two integer arrays nums1 and nums2 sorted in 
// ascending order and an integer k.
// Define a pair (u, v) which consists of one element from the 
// first array and one element from the second array.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with 
// the smallest sums.

// Example 1:
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the 
// sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

// Example 2:
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the 
// sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// Example 3:
// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [[1,3],[2,3]]
// Explanation: All possible pairs are returned from the 
// sequence: [1,3],[2,3]
 
// Constraints:
// 1 <= nums1.length, nums2.length <= 104
// -109 <= nums1[i], nums2[i] <= 109
// nums1 and nums2 both are sorted in ascending order.
// 1 <= k <= 1000

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        // defining min priority Queue.
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int nums1Length = nums1.size();
        int nums2Length = nums2.size();
        if(nums1Length == 0 || nums2Length == 0){
            return ans;
        }      

        for(int i=0;i<nums1Length;i++){
            pq.push({nums1[i] + nums2[0],{i,0}});
        }
        
        while(!pq.empty() && k > 0){
            pair<int,pair<int,int>> front = pq.top();
            pq.pop();
            ans.push_back({nums1[front.second.first],nums2[front.second.second]});
            if(front.second.first < nums1Length && front.second.second + 1 < nums2Length){
                pq.push({nums1[front.second.first] + nums2[front.second.second + 1],{front.second.first,front.second.second + 1}});
            }
            k--;          
        }

        return ans;      
    }
};