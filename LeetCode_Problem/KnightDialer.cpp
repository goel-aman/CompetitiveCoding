#include<bits/stdc++.h>
using namespace std;

// 935. Knight Dialer
// The chess knight has a unique movement, it may move two squares
//  vertically and one square horizontally, or two squares horizontally
//  and one square vertically (with both forming the shape of an L). The
//  possible movements of chess knight are shown in this diagaram:
// A chess knight can move as indicated in the chess diagram below:
// We have a chess knight and a phone pad as shown below, the knight can 
// only stand on a numeric cell (i.e. blue cell).

// Given an integer n, return how many distinct phone numbers of 
// length n we can dial.
// You are allowed to place the knight on any numeric cell initially and 
// then you should perform n - 1 jumps to dial a number of length n. All
//  jumps should be valid knight jumps.

// As the answer may be very large, return the answer modulo 109 + 7.

// Example 1:
// Input: n = 1
// Output: 10
// Explanation: We need to dial a number of length 1, so placing the knight
//  over any numeric cell of the 10 cells is sufficient.

// Example 2:
// Input: n = 2
// Output: 20
// Explanation: All the valid number we can dial are [04, 06, 16, 18, 27,
//  29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

// Example 3:
// Input: n = 3
// Output: 46

// Example 4:
// Input: n = 4
// Output: 104

// Example 5:
// Input: n = 3131
// Output: 136006598
// Explanation: Please take care of the mod.
 
// Constraints:
// 1 <= n <= 5000

class Solution {
    // vector<vector<char>> vec = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
    vector<vector<int>> directions;
    int rows;
    int cols;
    int mod = 1000000000 + 7;
    vector<vector<vector<int>>> dp;

public:
    int solve(int length,int i,int j){
        if(length == 0){
            return 1;
        }

        if(i >= rows || i < 0 || j >= cols || j < 0 || (i == 3 && j == 0) || (i == 3 && j == 2)){
            return 0;
        }
        
        if(dp[length][i][j] != -1){
            return dp[length][i][j];
        }

        int ans = 0;
        for(auto &var : directions){
            int x = i + var[0];
            int y = j  + var[1];
            if(x < rows && x >= 0 && y < cols &&  y >= 0 && !(x == 3 && y == 0) && !(x == 3 && y == 2)){
                ans = (ans + solve(length - 1,x,y))%mod;
            }
        }
        
        return dp[length][i][j] = ans;
    }


    int knightDialer(int n) {
        rows = 4;
        cols = 3;
        dp.resize(n + 1,vector<vector<int>>(rows,vector<int>(cols,-1)));
        // memset(dp,-1,sizeof(dp));
        int ans= 0;
        directions.push_back({-2,1});
        directions.push_back({-1,+2});
        directions.push_back({1,+2});
        directions.push_back({+2,+1});
        directions.push_back({+2,-1});
        directions.push_back({1,-2});
        directions.push_back({-1,-2});
        directions.push_back({-2,-1});
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!(i == 3 && j == 0) && !(i == 3 && j == 2)){
                   ans = (ans + solve(n - 1,i,j))%mod; 
                }
            }
        }
        return ans;
    }
};