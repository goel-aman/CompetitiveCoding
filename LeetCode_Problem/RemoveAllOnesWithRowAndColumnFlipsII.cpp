#include<bits/stdc++.h>
using namespace std;

// 2174. Remove All Ones With Row and Column Flips II
// You are given a 0-indexed m x n binary matrix grid.
// In one operation, you can choose any i and j that meet
//  the following conditions:
// 0 <= i < m
// 0 <= j < n
// grid[i][j] == 1
// and change the values of all cells in row i and column
//  j to zero.
// Return the minimum number of operations needed to 
// remove all 1's from grid.

// Example 1:
// Input: grid = [[1,1,1],[1,1,1],[0,1,0]]
// Output: 2
// Explanation:
// In the first operation, change all cell values of row 1
//  and column 1 to zero.
// In the second operation, change all cell values of row 0
//  and column 0 to zero.

// Example 2:
// Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
// Output: 2
// Explanation:
// In the first operation, change all cell values of row 1 
// and column 0 to zero.
// In the second operation, change all cell values of row 2
//  and column 1 to zero.
// Note that we cannot perform an operation using row 1 and
//  column 1 because grid[1][1] != 1.

// Example 3:
// Input: grid = [[0,0],[0,0]]
// Output: 0
// Explanation:
// There are no 1's to remove so return 0.
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 15
// 1 <= m * n <= 15
// grid[i][j] is either 0 or 1.

class Solution {
    int rows;
    int cols;
    vector<vector<int>> positionsOfOne;
    int positionsLength;
public:
    int minimumNumberOfOperations(vector<vector<int>> grid,int index){
        bool onesAreThere = false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    onesAreThere = true;
                    break;
                }
            }
            if(onesAreThere)
            {
                break;
            }
        }
        
        if(onesAreThere == false){
            return 0;
        }
        
        if(index == positionsLength){
            if(onesAreThere){
                return INT_MAX;
            }else{
                return 0;
            }
        }
        
        int row = positionsOfOne[index][0];
        int col = positionsOfOne[index][1];
        
        if(grid[row][col] == 0){
            return minimumNumberOfOperations(grid,index + 1);
        }
        // simply skipping this index's operation 
        int optionOne = minimumNumberOfOperations(grid,index + 1);
        
        // applying the operation on row and column
        for(int i=0;i<cols;i++){
            grid[row][i] = 0;
        }
        for(int i=0;i<rows;i++){
            grid[i][col] = 0;
        }
        
        int optionTwo = minimumNumberOfOperations(grid,index + 1);
        if(optionTwo != INT_MAX){
            optionTwo++;
        }
        return min(optionOne,optionTwo);
    }
    
    int removeOnes(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    positionsOfOne.push_back({i,j});
                }
            }
        }
        positionsLength = positionsOfOne.size();
        return minimumNumberOfOperations(grid,0);
    }
};