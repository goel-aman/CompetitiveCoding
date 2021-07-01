#include<bits/stdc++.h>
using namespace std;

// 304. Range Sum Query 2D - Immutable
// Given a 2D matrix matrix, handle multiple queries
//  of the following type:

// Calculate the sum of the elements of matrix inside the
//  rectangle defined by its upper left corner (row1, col1)
//  and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the
//  integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns 
// the sum of the elements of matrix inside the rectangle defined
//  by its upper left corner (row1, col1) and lower right 
// corner (row2, col2).
 
// Example 1:
// Input
// ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
// [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], 
// [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], 
// [1, 1, 2, 2], [1, 2, 2, 4]]
// Output
// [null, 8, 11, 12]

// Explanation
// NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], 
// [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
// numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
// numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
// numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// -105 <= matrix[i][j] <= 105
// 0 <= row1 <= row2 < m
// 0 <= col1 <= col2 < n
// At most 104 calls will be made to sumRegion.

class NumMatrix {
    vector<vector<int>> mat;
    vector<vector<int>> prefix;
    int rows,cols;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        
        rows = mat.size();
        cols = mat[0].size();
        prefix.resize(rows,vector<int>(cols,0));
        // cout<<"aman"<<endl;
        for(int i=0;i<cols;i++){
            if(i == 0){
                prefix[0][i] = mat[0][i];
                continue;
            }
            prefix[0][i] = prefix[0][i - 1] + mat[0][i]; 
        }
        // cout<<"hello2"<<endl;
        for(int j=0;j<rows;j++){
            if(j == 0){
                prefix[j][0] = mat[j][0];
                continue;
            }

            prefix[j][0] = prefix[j - 1][0] + mat[j][0];
        }
        // cout<<"hello1"<<endl;
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i][j];
            }
        }
        // cout<<"hello"<<endl;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2][col2];
        int top = 0,left = 0,diag = 0;
        if(row1 - 1 >= 0){
            top = prefix[row1 - 1][col2];
        }
        if(col1 - 1 >= 0){
            left = prefix[row2][col1 - 1];
        }

        if(row1 - 1 >= 0 && col1 - 1 >= 0){
            diag = prefix[row1 - 1][col1 - 1];
        }
        int val = sum - top - left  + diag;
        return val;
    }
};
