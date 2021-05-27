#include<bits/stdc++.h>
using namespace std;

// Alice and Bob take turns playing a game, with Alice starting first.

// There are n stones arranged in a row. On each player's turn, they can
//  remove either the leftmost stone or the rightmost stone from the row
//  and receive points equal to the sum of the remaining stones' values 
// in the row. The winner is the one with the higher score when there 
// are no stones left to remove.

// Bob found that he will always lose this game (poor Bob, he always loses),
//  so he decided to minimize the score's difference. Alice's goal is to 
// maximize the difference in the score.

// Given an array of integers stones where stones[i] represents the 
// value of the ith stone from the left, return the difference in Alice
//  and Bob's score if they both play optimally.

// Example 1:
// Input: stones = [5,3,1,4,2]
// Output: 6
// Explanation: 
// - Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
// - Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
// - Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
// - Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
// - Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
// The score difference is 18 - 12 = 6.

// Example 2:
// Input: stones = [7,90,5,1,100,10,10,2]
// Output: 122
 
// Constraints:
// n == stones.length
// 2 <= n <= 1000
// 1 <= stones[i] <= 1000


class Solution {
    int stonesLength;
    int dp[1001][1001][2];
public:
    // 1 means alice, 0 means bob.
    int StoneGame(vector<int>& stones,int start,int end,int sum,int chance){
        if(start == end){
            int a = 0, b= 0;
            if(chance == 1){
                a += 0;
            }
            else{
                b += 0;
            }
            return (a - b);
        }

        if(dp[start][end][chance] != -1){
            return dp[start][end][chance];
        }
        int value1 = INT_MIN, value2 = INT_MIN;
        if(chance == 1){
            value1 = sum - stones[start] + StoneGame(stones,start + 1,end,sum - stones[start],!chance);
            value2 = sum - stones[end] + StoneGame(stones,start,end - 1,sum - stones[end],!chance);
            return max(value1,value2);
        }

        value1 = INT_MAX, value2 = INT_MAX;
        
        value1 =  StoneGame(stones,start + 1,end,sum - stones[start],!chance) - (sum - stones[start]);
        value2 = StoneGame(stones,start,end - 1,sum - stones[end],!chance) - (sum - stones[end]);
        return dp[start][end][chance] = min(value1,value2); 
    }

    int stoneGameVII(vector<int>& stones) {
        stonesLength = stones.size();
        int sum =0;
        for(auto element : stones){
            sum += element;
        }
        memset(dp,-1,sizeof(dp));
        return StoneGame(stones,0,stonesLength - 1,sum,1);
    }
};