#include<bits/stdc++.h>
using namespace std;

// 311. Sparse Matrix Multiplication
// Given two sparse matrices mat1 of size m x k and mat2 of 
// size k x n, return the result of mat1 x mat2. You may 
// assume that multiplication is always possible.

// Example 1:
// Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
// Output: [[7,0,0],[-7,0,3]]

// Example 2:
// Input: mat1 = [[0]], mat2 = [[0]]
// Output: [[0]]

// Constraints:
// m == mat1.length
// k == mat1[i].length == mat2.length
// n == mat2[i].length
// 1 <= m, n, k <= 100
// -100 <= mat1[i][j], mat2[i][j] <= 100

class Solution {
public:
    int valueCalculation(vector<int> &first,vector<int> &second){
        int sum = 0;
        for(int i=0;i<first.size();i++){
            sum += (first[i] * second[i]);
        }
        return sum;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int firstRows = mat1.size();
        int firstCols = mat1[0].size();
        
        int secondRows = mat2.size();
        int secondCols = mat2[0].size();
        
        vector<vector<int>> ans(firstRows,(vector<int>(secondCols)));
        for(int i=0;i<firstRows;i++){
            for(int j=0;j<secondCols;j++){
                vector<int> temp(secondRows);
                int sum = 0;
                for(int k=0;k<secondRows;k++){
                    temp[k] = mat2[k][j];
                    sum += (mat1[i][k] * mat2[k][j]);
                }
                ans[i][j] = sum;
            } 
        }
        return ans;
    }
};