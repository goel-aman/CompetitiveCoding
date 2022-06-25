#include<bits/stdc++.h>
using namespace std;

// 329. Longest Increasing Path in a Matrix
// Given an m x n integers matrix, return the length of the 
// longest increasing path in matrix.

// From each cell, you can either move in four directions: 
// left, right, up, or down. You may not move diagonally or move 
// outside the boundary (i.e., wrap-around is not allowed).

// Example 1:
// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6].
//  Moving diagonally is not allowed.

// Example 3:
// Input: matrix = [[1]]
// Output: 1
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1


class Solution {
    int rows,cols;
    vector<vector<int>> storeResults;
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        if(rows == 0 || cols == 0){
            return 0;
        }
        
        storeResults.resize(rows,vector<int>(cols,-1));
        
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans = max(ans,solve(matrix,i,j));
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& matrix,int row,int col){
        int maxValue = 1;
        if(storeResults[row][col] != -1){
            return storeResults[row][col];
        }
        
        for(int i=0;i<4;i++){
            int currentRow = (row + moves[i][0]);
            int currentCol = (col + moves[i][1]);

            if(currentRow < rows && currentRow >= 0 && currentCol < cols && currentCol >= 0 && matrix[currentRow][currentCol] < matrix[row][col]){
                maxValue = max(maxValue,1 + solve(matrix,currentRow,currentCol));
            }
        }
        storeResults[row][col] = maxValue;
        return maxValue;
    }
};
