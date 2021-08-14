#include<bits/stdc++.h>
using namespace std;

// 1072. Flip Columns For Maximum Number of Equal Rows
// You are given an m x n binary matrix matrix.
// You can choose any number of columns in the matrix
//  and flip every cell in that column (i.e., Change the
//  value of the cell from 0 to 1 or vice versa).

// Return the maximum number of rows that have all values
//  equal after some number of flips.

// Example 1:
// Input: matrix = [[0,1],[1,1]]
// Output: 1
// Explanation: After flipping no values, 1 row has all
//  values equal.

// Example 2:
// Input: matrix = [[0,1],[1,0]]
// Output: 2
// Explanation: After flipping values in the first column,
//  both rows have equal values.

// Example 3:
// Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
// Output: 2
// Explanation: After flipping values in the first two
//  columns, the last two rows have equal values.

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is either 0 or 1.

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> um;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            int firstValue = matrix[i][0];
            string s = "";
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == firstValue){
                    s += "1";
                }else{
                    s += "0";
                }
            }
            um[s]++;
        }
        int ans = 0;
        for(auto &var : um){
            ans = max(ans,var.second);
        }
        return ans;
    }
};