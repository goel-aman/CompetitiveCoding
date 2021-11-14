#include<bits/stdc++.h>
using namespace std;

// 52. N-Queens II
// The n-queens puzzle is the problem of placing n 
// queens on an n x n chessboard such that no two
//  queens attack each other.
// Given an integer n, return the number of distinct 
// solutions to the n-queens puzzle.

// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to
//  the 4-queens puzzle as shown.

// Example 2:
// Input: n = 1
// Output: 1

// Constraints:
// 1 <= n <= 9


class Solution {
    int nValue;
    int ans = 0;

public:
    bool isSafe(int row,int col,vector<vector<int>>& queen){
        // checking same row
        for(int i=0;i<col;i++){
            if(queen[row][i] == 1){
                return false;
            }
        }

        // checking same col
        for(int i=0;i<row;i++){
            if(queen[i][col] == 1){
                return false;
            }
        }

        // checking top - right diagonal.
        for(int i=row,j = col;i>=0 && j< nValue;i--,j++){
            if(queen[i][j] == 1){
                return false;
            }
        }

        // checking top - left diagonal.
        for(int i=row,j = col;i>=0 && j >= 0;i--,j--){
            if(queen[i][j] == 1){
                return false;
            }
        }

        return true;
    }


    void solve(int row,int col,vector<vector<int>> &queen){
        if(row == nValue){
            ans++;
            return ;
        }

        for(int i = col;i<nValue;i++){
            bool check = isSafe(row,i,queen);
            if(check){
                queen[row][i] = 1;
                solve(row + 1,0,queen);
                queen[row][i] = 0;
            }
        }

        return ;
    }

    int totalNQueens(int n) {
        nValue = n;
        vector<vector<int>> queen(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            queen[0][i] = 1;
            solve(1,0,queen);
            queen[0][i] = 0;
        }
        return ans;
    }
};