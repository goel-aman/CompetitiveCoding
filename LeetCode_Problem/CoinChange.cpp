#include<bits/stdc++.h>
using namespace std;

// 322. Coin Change
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Example 3:
// Input: coins = [1], amount = 0
// Output: 0

// Example 4:
// Input: coins = [1], amount = 1
// Output: 1

// Example 5:
// Input: coins = [1], amount = 2
// Output: 2
 
// Constraints:
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

class Solution {
    int coinsLength;
    int dp[13][10001];
public:
    int getAnswer(vector<int>& coins,int index,int amount){
        
        if(amount < 0){
            return INT_MAX;
        }

        if(amount == 0){
            return 0;
        }
        
        if(index >= coinsLength){
            return INT_MAX;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int maxCount = amount / coins[index];
        long int value = INT_MAX;
        for(int i=0;i<=maxCount;i++){
            if(i == 0){
                value = min(value,(long) getAnswer(coins,index + 1, amount));
            }
            value = min(value, (i + (long)getAnswer(coins,index + 1,amount - (coins[index] * i))));
        }       
        return dp[index][amount] = value;
    }

    int coinChange(vector<int>& coins, int amount) {
        coinsLength = coins.size();
        memset(dp,-1,sizeof(dp));
        int value = getAnswer(coins,0,amount);
        if(value >= INT_MAX){
            return -1;
        }
        
        return value;
    }
};