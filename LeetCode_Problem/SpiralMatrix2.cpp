// Spiral Matrix II
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]
 
// Constraints:
// 1 <= n <= 20

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(vector<vector<int>>& mat,int start_i,int start_j,vector<int>& elements,int n,int index){
        
        if(n == 0){
            return ;
        }
        if(n == 1){
            mat[start_i][start_j] = elements[index];
            return ;
        }

        if(n == 2){
            mat[start_i][start_j] = elements[index];
            index++;
            mat[start_i][start_j + 1] = elements[index];
            index++;
            mat[start_i + 1][start_j + 1] = elements[index];
            index++;
            mat[start_i + 1][start_j] = elements[index];
            return ; 
        }
        // filling row
        for(int i=start_i;i<start_i + n;i++){
            
            mat[start_i][i] = elements[index];
            index++;
        }

        // filling last column 
        int col = n + start_i - 1;
        for(int i=start_i + 1;i<start_i + n;i++){
            mat[i][col] = elements[index];
            index++;
        }

        int row = start_i + n - 1;
        // filling last row
        for(int i=start_i + n - 2;i>=start_i;i--)
        {
            mat[row][i] = elements[index];
            index++;
        }
        col = start_i;
        // filling first column
        for(int i=start_i + n - 2;i>=start_i + 1;i--){
            mat[i][col] = elements[index];
            index++;
        }
        func(mat,start_i + 1,start_j + 1,elements,n - 2,index);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        vector<int> elements;
        for(int i=1;i<=n*n;i++){
            elements.push_back(i);
        }
        func(ans,0,0,elements,n,0);
        return ans;
    }
};