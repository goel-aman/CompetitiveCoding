#include<bits/stdc++.h>
using namespace std;

// 1906. Minimum Absolute Difference Queries
// The minimum absolute difference of an array a is defined as
//  the minimum value of |a[i] - a[j]|, where 0 <= i < j < a.length
//  and a[i] != a[j]. If all elements of a are the same, the minimum
//  absolute difference is -1.

// For example, the minimum absolute difference of the 
// array [5,2,3,7,2] is |2 - 3| = 1. Note that it is not 0 
// because a[i] and a[j] must be different.
// You are given an integer array nums and the array queries where 
// queries[i] = [li, ri]. For each query i, compute the minimum absolute 
// difference of the subarray nums[li...ri] containing the elements of nums
//  between the 0-based indices li and ri (inclusive).

// Return an array ans where ans[i] is the answer to the ith query.
// A subarray is a contiguous sequence of elements in an array.
// The value of |x| is defined as:
// x if x >= 0.
// -x if x < 0.
 
// Example 1:
// Input: nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
// Output: [2,1,4,1]
// Explanation: The queries are processed as follows:
// - queries[0] = [0,1]: The subarray is [1,3] and the minimum 
// absolute difference is |1-3| = 2.
// - queries[1] = [1,2]: The subarray is [3,4] and the minimum
//  absolute difference is |3-4| = 1.
// - queries[2] = [2,3]: The subarray is [4,8] and the minimum
//  absolute difference is |4-8| = 4.
// - queries[3] = [0,3]: The subarray is [1,3,4,8] and the minimum
//  absolute difference is |3-4| = 1.

// Example 2:
// Input: nums = [4,5,2,2,7,10], queries = [[2,3],[0,2],[0,5],[3,5]]
// Output: [-1,1,1,3]
// Explanation: The queries are processed as follows:
// - queries[0] = [2,3]: The subarray is [2,2] and the minimum 
// absolute difference is -1 because all the
//   elements are the same.
// - queries[1] = [0,2]: The subarray is [4,5,2] and the minimum 
// absolute difference is |4-5| = 1.
// - queries[2] = [0,5]: The subarray is [4,5,2,2,7,10] and the 
// minimum absolute difference is |4-5| = 1.
// - queries[3] = [3,5]: The subarray is [2,7,10] and the minimum 
// absolute difference is |7-10| = 3.
 
// Constraints:
// 2 <= nums.length <= 105
// 1 <= nums[i] <= 100
// 1 <= queries.length <= 2 * 104
// 0 <= li < ri < nums.length




class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int numsLength = nums.size();
        vector<vector<int>> vec(numsLength,vector<int> (101,0));

        for(int i=0;i<numsLength;i++){
            if(i != 0){
                vec[i] = vec[i  - 1];
            }
            vec[i][nums[i]] += 1;
        }
        int queriesLength = queries.size();
        // cout<<"process completed"<<endl;
        vector<int> ans(queriesLength,0);
        for(int i=0;i<queriesLength;i++){
            int start = queries[i][0] , end = queries[i][1];
            vector<int> temp;
            if(start != 0){
                for(int j=0;j<101;j++){
                    if(vec[end][j] - vec[start - 1][j] > 0){
                        temp.push_back(j);
                    } 
                }
            }else{
                for(int j=0;j<101;j++){
                    if(vec[end][j] > 0){
                        temp.push_back(j);
                    }
                }
            }
            // cout<<"hello"<<endl;
            int minDifference = INT_MAX;
            int first,second;
            for(int j=0;j<temp.size();j++){
                if(j == 0){
                    first = temp[0];
                    continue;
                }

                second = temp[j];
                minDifference = min(second - first,minDifference);
                first = second;
            }       
            if(minDifference == INT_MAX){
                ans[i] = -1;
            }else{
                ans[i] = minDifference;
            }
        }
        return ans;
    }
};