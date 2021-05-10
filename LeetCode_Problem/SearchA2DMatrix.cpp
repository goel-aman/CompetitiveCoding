#include<bits/stdc++.h>
using namespace std;

// 74. Search a 2D Matrix

// Write an efficient algorithm that searches for a value in an m x n matrix.
//  This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int end = (rows * cols)  - 1;
        int start = 0;
        while(start <= end){
            int mid = (start + end) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if(matrix[row][col] == target){
                return true;
            }

            if(matrix[row][col] < target){
                start = mid + 1;
                continue;
            }

            if(matrix[row][col] > target){
                end = mid - 1;
                continue;
            }
        }
        return false;
    }
};