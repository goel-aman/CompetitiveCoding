// 1314. Matrix Block Sum

// Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] 
// is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c)
//  is a valid position in the matrix.
 

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]
// Example 2:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
// Output: [[45,45,45],[45,45,45],[45,45,45]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n, K <= 100
// 1 <= mat[i][j] <= 100


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> prefixSum(rows,vector<int>(cols));
        vector<vector<int>> answer(rows,vector<int>(cols));
        for(int i=0;i<cols;i++){
            if(i == 0){
                prefixSum[0][i] = mat[0][i];
                continue;
            }
            prefixSum[0][i] = prefixSum[0][i -1] + mat[0][i];
        }

        for(int i=0;i<rows;i++){
            if(i == 0){
                prefixSum[i][0] = mat[i][0];
                continue;
            }
            prefixSum[i][0] = prefixSum[i - 1][0] + mat[i][0];  
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                prefixSum[i][j] = mat[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }
        // cout<<"printing PrefixSum : "<<endl;
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         cout<<prefixSum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int r2 = min(i + K,rows - 1);
                int c2 = min(j + K,cols - 1);

                answer[i][j] = prefixSum[r2][c2];
                if(i - K - 1 >= 0){
                    answer[i][j] -=  prefixSum[i - K - 1][c2];
                }
                if(j - K - 1 >=0){
                    answer[i][j] = answer[i][j] - prefixSum[r2][j - K - 1];
                }
                if(i - K - 1 >= 0 && j - K - 1 >=0 ){
                    answer[i][j] = answer[i][j] + prefixSum[i - K - 1][j - K - 1];
                }
            }
        }
        return answer;
    }
};