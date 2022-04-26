#include<bits/stdc++.h>
using namespace std;

// 1940. Longest Common Subsequence Between Sorted Arrays
// Given an array of integer arrays arrays where each arrays[i]
//  is sorted in strictly increasing order, return an integer 
// array representing the longest common subsequence between 
// all the arrays.

// A subsequence is a sequence that can be derived from another 
// sequence by deleting some elements (possibly none) without
//  changing the order of the remaining elements.

// Example 1:
// Input: arrays = [[1,3,4],
//                  [1,4,7,9]]
// Output: [1,4]
// Explanation: The longest common subsequence in the two arrays is [1,4].

// Example 2:
// Input: arrays = [[2,3,6,8],
//                  [1,2,3,5,6,7,10],
//                  [2,3,4,6,9]]
// Output: [2,3,6]
// Explanation: The longest common subsequence in all three arrays is [2,3,6].

// Example 3:
// Input: arrays = [[1,2,3,4,5],
//                  [6,7,8]]
// Output: []
// Explanation: There is no common subsequence 
// between the two arrays.

// Constraints:
// 2 <= arrays.length <= 100
// 1 <= arrays[i].length <= 100
// 1 <= arrays[i][j] <= 100
// arrays[i] is sorted in strictly
//  increasing order.

class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> ans;
        unordered_map<int,int> um;
        int arrsize = arrays.size();

        for(int i=0;i<arrsize;i++){
            for(int j=0;j<arrays[i].size();j++){
                um[arrays[i][j]]++;
                if(um[arrays[i][j]] == arrsize){
                    ans.push_back(arrays[i][j]);
                }
            }
        }
        return ans;
    }
};