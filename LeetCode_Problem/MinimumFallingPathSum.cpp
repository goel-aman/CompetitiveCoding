#include<bits/stdc++.h>
using namespace std;

// 931. Minimum Falling Path Sum
// Given an n x n array of integers matrix, return the
//  minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row 
// and chooses the element in the next row that is either
//  directly below or diagonally left/right. Specifically,
//  the next element from position (row, col) will be 
// (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum 
// sum underlined below:
// [[2,1,3],      [[2,1,3],
//  [6,5,4],       [6,5,4],
//  [7,8,9]]       [7,8,9]]

// Example 2:
// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is underlined below:
// [[-19,57],
//  [-40,-5]]

// Example 3:
// Input: matrix = [[-48]]
// Output: -48
 
// Constraints:
// n == matrix.length
// n == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> vec = {{1,-1},{1,0},{1,1}};
        // vector<vector<int>> ans(matrix.begin(),matrix.end());
        int finalAns = INT_MAX;
        for(int i=rows - 1;i>=0;i--){
            for(int j=cols - 1;j>=0;j--){
                int val = INT_MAX;
                for(auto var : vec){
                    int row = i + var[0];
                    int col = j + var[1];
                    if(row >= 0 && row < rows && col >= 0 && col < cols){
                        val = min(val,matrix[row][col]);
                    }
                }
                if(val == INT_MAX){
                    matrix[i][j] = matrix[i][j];
                }else{
                    matrix[i][j] = matrix[i][j] + val;
                }
                if(i == 0){
                    finalAns = min(finalAns,matrix[i][j]);
                }
            }
        }
        return finalAns;
    }
};