#include<bits/stdc++.h>
using namespace std;

// 221. Maximal Square
// Given an m x n binary matrix filled with 0's and 1's, find the
//  largest square containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],
// ["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4

// Example 2:
// Input: matrix = [["0","1"],["1","0"]]
// Output: 1

// Example 3:
// Input: matrix = [["0"]]
// Output: 0
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> mat(rows,vector<int>(cols,0));
        int ans = 0;

        for(int i=0;i<rows;i++){
            if(matrix[i][0] == '1'){
                mat[i][0] = 1;
                ans = max(ans,1);
            }else{
                mat[i][0] = 0;
            }
        }

        for(int i=0;i<cols;i++){
             if(matrix[0][i] == '1'){
                 mat[0][i] = 1;
                 ans = max(ans, 1);
             }else{
                 mat[0][i] = 0;
             }
        }
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j] == '1'){
                    mat[i][j] = 1 + min(mat[i - 1][j],min(mat[i -1][j - 1],mat[i][j - 1]));
                    ans = max(ans,mat[i][j]);
                }else{
                    mat[i][j] = 0;
                }
            }
        }
        return ans*ans;
    }
};