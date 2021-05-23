#include<bits/stdc++.h>
using namespace std;

// 63. Unique Paths II
// A robot is located at the top-left corner of a m x n grid
//  (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point
//  in time. The robot is trying to reach the bottom-right corner 
// of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids.
//  How many unique paths would there be?

// An obstacle and space is marked as 1 and 0 respectively
//  in the grid. 

// Example 1:
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:
// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1
 
// Constraints:
// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> temp(rows,vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            else{
                temp[i][0] =1;
            }
        }

        for(int i=0;i<cols;i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            else{
                temp[0][i] = 1;
            }
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j] != 1){
                    temp[i][j] = temp[i - 1][j] + temp[i][j - 1];    
                }
                
            }
        }
        return temp[rows- 1][cols - 1];
    }
};