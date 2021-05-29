#include<bits/stdc++.h>
using namespace std;

// 1424. Diagonal Traverse II

// Given a list of lists of integers, nums, return all elements of
//  nums in diagonal order as shown in the below images.
 
// Example 1:
// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,4,2,7,5,3,8,6,9]

// Example 2:
// Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
// Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

// Example 3:
// Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
// Output: [1,4,2,5,3,8,6,9,7,10,11]

// Example 4:
// Input: nums = [[1,2,3,4,5,6]]
// Output: [1,2,3,4,5,6]
 
// Constraints:
// 1 <= nums.length <= 10^5
// 1 <= nums[i].length <= 10^5
// 1 <= nums[i][j] <= 10^9
// There at most 10^5 elements in nums.

class Solution {
    vector<int> ans;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();
        vector<vector<int>> visited;
        for(int i=0;i<nums.size();i++){
            vector<int> temp(nums[i].size(),0);
            visited.push_back(temp);
        }

        queue<pair<int,int>> que;
        que.push({0,0});
        visited[0][0] = true;
        while(!que.empty()){
            int siz = que.size();
            while(siz--){
                pair<int,int> front = que.front();
                que.pop();
                ans.push_back(nums[front.first][front.second]);

                if(front.first + 1 < rows && front.first + 1 >= 0 && nums[front.first + 1].size() > front.second && visited[front.first + 1][front.second] == 0){
                    visited[front.first + 1][front.second] = true;
                    que.push({front.first + 1,front.second});
                }

                if(front.second + 1 < nums[front.first].size() && front.second + 1 >= 0 && visited[front.first][front.second + 1] == 0 ){
                    visited[front.first][front.second + 1] = true;
                    que.push({front.first,front.second + 1});
                }
            }
        }
        return ans; 
    }
};