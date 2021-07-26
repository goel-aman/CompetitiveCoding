#include<bits/stdc++.h>
using namespace std;

// 714. Best Time to Buy and Sell Stock with Transaction Fee
// You are given an array prices where prices[i] is the price
//  of a given stock on the ith day, and an integer fee 
// representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as
//  many transactions as you like, but you need to pay the 
// transaction fee for each transaction.
// Note: You may not engage in multiple transactions simultaneously
//  (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

// Example 2:
// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
 
// Constraints:
// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104

class Solution {
    int dp[50001];
    int pricesLength;
public:
    // state = 1 means i already have a stock in hand
    // state = 0 means i don't have any stock in hand
    int Profit(vector<int>& prices,int& fee,int index){
        if(index == pricesLength){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // to simply move ahead;
        int value1 = Profit(prices,fee,index + 1);

        int value2 = INT_MIN;
        for(int i=index + 1;i<pricesLength;i++){
            value2 = max(value2,prices[i] - prices[index] - fee + Profit(prices,fee,i + 1));
        }
        return dp[index] = max(value2,value1);
    }

    int maxProfit(vector<int>& prices, int fee) {
        pricesLength = prices.size();
        memset(dp,-1,sizeof(dp));
        int ans = Profit(prices,fee,0);
        return ans;
    }
};