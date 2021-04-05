// 1444. Number of Ways of Cutting a Pizza
// Given a rectangular pizza represented as a rows x cols matrix containing the following
//  characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to 
// cut the pizza into k pieces using k-1 cuts. 
// For each cut you choose the direction: vertical or horizontal, then you choose a cut 
// position at the cell boundary and cut the pizza into two pieces. If you cut the pizza 
// vertically, give the left part of the pizza to a person. If you cut the pizza horizontally,
//  give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

// Return the number of ways of cutting the pizza such that each piece contains at least one apple.
//  Since the answer can be a huge number, return this modulo 10^9 + 7.

// Example 1:
// Input: pizza = ["A..","AAA","..."], k = 3
// Output: 3 
// Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

// Example 2:
// Input: pizza = ["A..","AA.","..."], k = 3
// Output: 1

// Example 3:
// Input: pizza = ["A..","A..","..."], k = 1
// Output: 1

// Constraints:
// 1 <= rows, cols <= 50
// rows == pizza.length
// cols == pizza[i].length
// 1 <= k <= 10
// pizza consists of characters 'A' and '.' only.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rows;
    int cols;
    int mod = 1000000000 + 7;
    // row, col,k
    int dp[51][51][11];
public:
    Solution(){
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                for(int k=0;k<11;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    int totalWays(vector<string>& pizza,int k,int row,int col){
        if(k <= 0){
            return 0;
        }

        if(k == 1){
            int count = 0;
            bool check = false;
            for(int i = row;i<rows;i++){
                for(int j = col;j<cols;j++){
                    if(pizza[i][j] == 'A'){
                        check = true;
                        break;
                    }
                }
            }
            if(check == 1){
                return 1;
            }
            return 0;
        }

        if(dp[row][col][k] != -1){
            return dp[row][col][k];
        }

        int ans = 0;
        // Lets Go for vertical cut first;
        for(int j = col + 1;j<cols;j++){
            bool check = false;
            for(int ii = row;ii < rows;ii++){
                for(int jj = col;jj < j;jj++){
                    if(pizza[ii][jj] == 'A'){
                        check = true;
                        break;
                    }
                }
            }

            if(check == 1){
                ans = (ans +  totalWays(pizza,k - 1,row,j))%mod;
            }
        }

        for(int i = row + 1;i <rows;i++){
            bool check = false;
            for(int ii = row; ii < i;ii++){
                for(int jj = col;jj < cols;jj++){
                    if(pizza[ii][jj] == 'A'){
                        check = true;
                        break;
                    }
                }
            }

            if(check == 1){
                ans = (ans +  totalWays(pizza,k - 1,i,col))%mod;
            }
        }

        return dp[row][col][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        rows = pizza.size();
        cols = pizza[0].size();
        return totalWays(pizza,k,0,0);
    }
};