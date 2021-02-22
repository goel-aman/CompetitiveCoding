// 1289. Minimum Falling Path Sum II

// Given a square grid of integers arr, a falling path with non-zero shifts is a 
// choice of exactly one element from each row of arr, such that no two elements 
// chosen in adjacent rows are in the same column.

// Return the minimum sum of a falling path with non-zero shifts.

// Example 1:
// Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
// Output: 13
// Explanation: 
// The possible falling paths are:
// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
// The falling path with the smallest sum is [1,5,7], so the answer is 13.

// Constraints:
// 1 <= arr.length == arr[i].length <= 200
// -99 <= arr[i][j] <= 99

#include<bits/stdc++.h>
using namespace std;



class Solution {
    int dp[201][201];
public:
    int getAnswer(vector<vector<int>> &arr,int currentRow,int prevColumn,int &totalRows,int &totalColumns){
        if(currentRow >= totalRows){
            return 0;
        }
        
        if(prevColumn != -1){
            if(dp[currentRow][prevColumn] != -1){
                return dp[currentRow][prevColumn];
            }    
        }
        

        int ans = INT_MAX;
        for(int i=0;i<totalColumns;i++){
            if(i != prevColumn){
                int val = getAnswer(arr,currentRow + 1,i,totalRows,totalColumns) + arr[currentRow][i];
                ans = min(val,ans); 
            }
        }
        if(prevColumn != -1){
            dp[currentRow][prevColumn] = ans;    
        }
        
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        // memset(dp,-1,sizeof(dp));
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                dp[i][j] = -1;
            }
        }
        return getAnswer(arr,0,-1,rows,cols);      
    }
};