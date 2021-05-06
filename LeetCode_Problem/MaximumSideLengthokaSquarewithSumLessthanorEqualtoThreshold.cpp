#include<bits/stdc++.h>
using namespace std;

// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// Given a m x n matrix mat and an integer threshold. Return the maximum side-length
//  of a square with a sum less than or equal to threshold or return 0 if there is no such square.

// Example 1:
// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

// Example 2:
// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
// Output: 0

// Example 3:
// Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
// Output: 3

// Example 4:
// Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
// Output: 2
 
// Constraints:
// 1 <= m, n <= 300
// m == mat.length
// n == mat[i].length
// 0 <= mat[i][j] <= 10000
// 0 <= threshold <= 10^5

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int answer = 0;
        int matRow = mat.size();
        int matCol = mat[0].size();
        
        int prefixMatrix[matRow + 1][matCol + 1];
        for(int i=0;i<=matRow;i++){
            prefixMatrix[i][0] = 0;
        }

        for(int i=0;i<=matCol;i++){
            prefixMatrix[0][i] = 0;
        }

        for(int i=1;i<=matRow;i++){
            for(int j=1;j<=matCol;j++){
                prefixMatrix[i][j] =  prefixMatrix[i - 1][j] + prefixMatrix[i][j - 1] - prefixMatrix[i - 1][j - 1] + mat[i - 1][j - 1]; 
            }
        }

        int start = 1 , end = min(matRow,matCol);
        while(start <= end){
            int mid = (start + end) / 2;
            int gotAnswer = false;
            for(int i=mid;i<=matRow;i++){
                for(int j=mid;j<=matCol;j++){
                    int sum = prefixMatrix[i][j] - prefixMatrix[i - mid][j] - prefixMatrix[i][j - mid] + prefixMatrix[i - mid][j - mid];
                    if(sum <= threshold){
                        gotAnswer = true;
                        break;
                    }                  
                }
                if(gotAnswer == true){
                    break;
                }
            }
            if(gotAnswer == true){
                answer = max(answer,mid);
                start = mid + 1;
                continue;
            }

            if(gotAnswer == false){
                end = mid - 1;
                continue;
            }            
        }
        return answer;
    }
};