#include<bits/stdc++.h>
using namespace std;

// 2128. Remove All Ones With Row and Column Flips
// You are given an m x n binary matrix grid.
// In one operation, you can choose any row or 
// column and flip each value in that row or 
// column (i.e., changing all 0's to 1's, and
//  all 1's to 0's).

// Return true if it is possible to remove all 1's 
// from grid using any number of operations or false
//  otherwise.

// Example 1:
// Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
// Output: true
// Explanation: One possible way to remove all 1's 
// from grid is to:
// - Flip the middle row
// - Flip the middle column

// Example 2:
// Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
// Output: false
// Explanation: It is impossible to remove all 1's 
// from grid.

// Example 3:
// Input: grid = [[0]]
// Output: true
// Explanation: There are no 1's in grid.
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is either 0 or 1.

class Solution {
    int rows;
    int cols;
public:
    
    bool isEqual(vector<int> first,vector<int> second){
        for(int i=0;i<cols;i++){
            if(first[i] != second[i]){
                return false;
            }
        }
        return true;
    }
    
    bool removeOnes(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        vector<int> first(cols);
        vector<int> second(cols);
        
        for(int i=0;i<cols;i++){
            first[i] = grid[0][i];
            second[i] = !grid[0][i];
        }
        
        for(int i=0;i<rows;i++){
            if(isEqual(first,grid[i]) || isEqual(second,grid[i])){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};