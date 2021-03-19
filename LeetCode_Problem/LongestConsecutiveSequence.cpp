// 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of
//  the longest consecutive elements sequence.

// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Constraints:
// 0 <= nums.length <= 104
// -109 <= nums[i] <= 109

// Follow up: Could you implement the O(n) solution?

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    unordered_map<int, int> parent;
    unordered_map<int,int> value;

    int findParent(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void merge(int x,int y)
    {
        int xPar = findParent(x);
        int yPar = findParent(y);
        if(xPar != yPar){
            value[xPar] = value[xPar] + value[yPar];
            value[yPar] = value[xPar];
            parent[xPar] = yPar;
        }
        return;
    }
public:
    int longestConsecutive(vector<int> &nums)
    {
        if(nums.size() == 0){
            return 0;
        }
        for(auto x : nums){
            parent[x] = x;
            value[x] = 1;
        }
        int ans = 1;
        for(auto x: nums){
            if(parent.count(x + 1) > 0){
                int first = findParent(x);
                int second = findParent(x + 1);
                if(first != second){
                    merge(first,second);
                }
                ans = max(value[first],ans);
                ans = max(value[second],ans);
            }

            if(parent.count(x - 1) > 0){
                int first = findParent(x);
                int second = findParent(x - 1);
                if(first != second){
                    merge(x,x -1);
                }
                ans = max(value[first],ans);
                ans = max(value[second],ans);
            }
        }
        return ans;
    }
};