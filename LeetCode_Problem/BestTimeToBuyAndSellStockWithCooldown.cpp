#include<bits/stdc++.h>
using namespace std;

// 309. Best Time to Buy and Sell Stock with Cooldown

// You are given an array prices where prices[i] is the
//  price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as
//  many transactions as you like (i.e., buy one and sell one share
//  of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the 
// next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously
//  (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// Example 2:
// Input: prices = [1]
// Output: 0
 
// Constraints:
// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000

class Solution {
    int dp[5002][1003];
    int pricesLength;
public:
    int maxProfit(vector<int>& prices,int index,bool prevBuy,int prevValue){
         if(index >= pricesLength){
            return 0;
        }

        if(dp[index][prevValue] != -1){
            return dp[index][prevValue];
        }

        int profit = 0;

        if(prevBuy == true){
            // case - 1 sell the current holding.
            profit = max(profit,prices[index] - prevValue + maxProfit(prices,index + 2,false,1002));

            // simply leave and move.
            profit = max(profit,maxProfit(prices,index + 1,prevBuy,prevValue));
            return profit;
        }

        // case - 1 buy at this position
        profit = max(maxProfit(prices,index + 1, true,prices[index]),maxProfit(prices,index + 1,false,1002));
        return dp[index][prevValue] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        pricesLength = prices.size();
        return maxProfit(prices,0,false,1002);
    }
};