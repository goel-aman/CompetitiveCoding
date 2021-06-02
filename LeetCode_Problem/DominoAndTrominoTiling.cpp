#include<bits/stdc++.h>
using namespace std;

// 790. Domino and Tromino Tiling

// We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape.
//  These shapes may be rotated.

// XX  <- domino
// XX  <- "L" tromino
// X
// Given n, how many ways are there to tile a 2 x n board? Return your answer
//  modulo 109 + 7.

// (In a tiling, every square must be covered by a tile. Two tilings are different
//  if and only if there are two 4-directionally adjacent cells on the board such
//  that exactly one of the tilings has both squares occupied by a tile.)

// Example:
// Input: n = 3
// Output: 5
// Explanation: 
// The five different ways are listed below, different letters indicates different tiles:
// XYZ XXZ XYY XXY XYY
// XYZ YYZ XZZ XYY XXY

// Note:
// n will be in range [1, 1000].
 

class Solution {
    int dp[1001][4];
    int length;
    int mod = 1e9 + 7;
public:

    int makeState(int t1,int t2){
        if(t1 && t2){
            return 0;
        }

        if(t1 && !t2){
            return 1;
        }

        if(!t1 && t2){
            return 2;
        }

        return 3;
    }

    // 1 means it is not filled && 0 means filled
    int solve(int index,int t1,int t2){
        if(index == length){
            return 1;
        }
        int state = makeState(t1,t2);
        if(dp[index][state] != -1){
            return dp[index][state];
        }

        int t3 = 0 , t4 = 0;
        if(index + 1 < length){
            t3 = 1;
            t4 = 1;
        }
        int count = 0;
        if(t1 && t2 && t3){
            count  = (count +  solve(index + 1,0,1))%mod;  
        }

        if(t1 && t2 && t4){
            count = (count + solve(index + 1,1,0))%mod; 
        }

        if(!t1 && !t2){
            count = (count + solve(index + 1,1,1))%mod; 
        }

        if(t1 && t2){
            count = (count +  solve(index + 1,1,1))%mod; 
        }

        if(t1 && !t2 && t3 && t4){
            count = (count +  solve(index + 1,0,0))%mod; 
        }

        if(!t1 && t2 && t3 && t4){
            count = (count + solve(index + 1,0,0))%mod; 
        }

        if(t1 && t2 && t3 && t4){
            count = (count + solve(index + 1,0,0))%mod; 
        }

        if(!t1 && t2 && t4){
            count = (count + solve(index + 1,1,0))%mod; 
        }

        if(t1 && !t2 && t3){
            count = (count +  solve(index + 1,0,1))%mod; 
        }
        return dp[index][state] = (count % mod);
    }

    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        length = n;
        return solve(0,1,1);
    }
};