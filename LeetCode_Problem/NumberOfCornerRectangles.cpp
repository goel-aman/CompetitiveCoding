#include<bits/stdc++.h>
using namespace std;

// 750. Number Of Corner Rectangles

// Given an m x n integer matrix grid where each entry 
// is only 0 or 1, return the number of corner rectangles.

// A corner rectangle is four distinct 1's on the grid that 
// forms an axis-aligned rectangle. Note that only the 
// corners need to have the value 1. Also, all four 1's 
// used must be distinct.

// Example 1:
// Input: grid = [[1,0,0,1,0],[0,0,1,0,1],[0,0,0,1,0],[1,0,1,0,1]]
// Output: 1
// Explanation: There is only one corner rectangle, with 
// corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].

// Example 2:
// Input: grid = [[1,1,1],[1,1,1],[1,1,1]]
// Output: 9
// Explanation: There are four 2x2 rectangles, four 2x3 and
//  3x2 rectangles, and one 3x3 rectangle.

// Example 3:
// Input: grid = [[1,1,1,1]]
// Output: 0
// Explanation: Rectangles must have four distinct corners.
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// grid[i][j] is either 0 or 1.
// The number of 1's in the grid is in the range [1, 6000].


class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        unordered_map<int,unordered_set<int>> onesPosition;
        int sum = 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    onesPosition[i].insert(j);
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j = i + 1;j<rows;j++){
                int commonCount = 0;
                
                for(auto var : onesPosition[i]){
                    if(onesPosition[j].count(var)){
                        commonCount++;
                    }
                }
                
                if(commonCount > 1){
                    sum += (((commonCount - 1) * (commonCount))/ 2);
                }
            }
        }
        return sum;
    }
};