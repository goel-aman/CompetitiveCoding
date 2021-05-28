// 877. Stone Game

// Alex and Lee play a game with piles of stones.  There are an even number of piles 
// arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones.  The total number of 
// stones is odd, so there are no ties.

// Alex and Lee take turns, with Alex starting first.  Each turn, a player takes
//  the entire pile of stones from either the beginning or the end of the row.  
// This continues until there are no more piles left, at which point the person 
// with the most stones wins.

// Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

// Example 1:
// Input: piles = [5,3,4,5]
// Output: true
// Explanation: 
// Alex starts first, and can only take the first 5 or the last 5.
// Say he takes the first 5, so that the row becomes [3, 4, 5].
// If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
// If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 
// Constraints:
// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles) is odd.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int length;
    int dp[501][501];
public:
    int canWin(vector<int>& piles,int start ,int end,int sum){
        if(start == end){
            return piles[start];
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int value1 = INT_MAX, value2 = INT_MAX;
        value1 = sum - canWin(piles,start + 1,end, sum - piles[start]);
        value2 = sum - canWin(piles,start,end - 1,sum - piles[end]);

        return dp[start][end] = max(value1,value2);
    }

    bool stoneGame(vector<int>& piles) {
        length = piles.size();
        int sum = 0;

        for(auto element : piles){
            sum += element;
        }
        memset(dp,-1,sizeof(dp));
        int iGot =  canWin(piles,0,length - 1,sum);
        int heGot = sum - iGot;

        if(iGot > heGot){
            return true;
        }     
        return false;
    }
};
class Solution {
    int length;
    int dp[501][501];
public:
    int canWin(vector<int>& piles,int start ,int end,int sum){
        if(start == end){
            return piles[start];
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int value1 = INT_MAX, value2 = INT_MAX;
        value1 = sum - canWin(piles,start + 1,end, sum - piles[start]);
        value2 = sum - canWin(piles,start,end - 1,sum - piles[end]);

        return dp[start][end] = max(value1,value2);
    }

    bool stoneGame(vector<int>& piles) {
        length = piles.size();
        int sum = 0;

        for(auto element : piles){
            sum += element;
        }
        memset(dp,-1,sizeof(dp));
        int iGot =  canWin(piles,0,length - 1,sum);
        int heGot = sum - iGot;

        if(iGot > heGot){
            return true;
        }     
        return false;
    }
};