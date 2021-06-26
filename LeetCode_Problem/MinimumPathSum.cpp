#include<bits/stdc++.h>
using namespace std;

// 64. Minimum Path Sum

// Given a m x n grid filled with non-negative numbers, find a path from top
//  left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 100

class Solution {
    int rows;
    int cols;
    int dp[201][201];
public:
    int minPathSumm(vector<vector<int>>& grid,int i,int j){
        if(i == rows - 1 && j == cols - 1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        int ans = INT_MAX;
        if(j + 1 < cols){
            ans = min(ans,minPathSumm(grid,i,j + 1));
        }

        if(i + 1 < rows){
            ans = min(ans,minPathSumm(grid,i + 1,j));
        }

        return dp[i][j] = (ans + grid[i][j]);
    }

    int minPathSum(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return minPathSumm(grid,0,0);
    }
};