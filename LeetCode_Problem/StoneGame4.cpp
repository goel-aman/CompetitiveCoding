// 1510. Stone Game IV

// Alice and Bob take turns playing a game, with Alice starting first.
// Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of 
// removing any non-zero square number of stones in the pile.
// Also, if a player cannot make a move, he/she loses the game.
// Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, 
// assuming both players play optimally.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.

// Example 2:
// Input: n = 2
// Output: false
// Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).

// Example 3:
// Input: n = 4
// Output: true
// Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).

// Example 4:
// Input: n = 7
// Output: false
// Explanation: Alice can't win the game if Bob plays optimally.
// If Alice starts removing 4 stones, Bob will remove 1 stone then Alice should remove only 1 stone and finally Bob removes the last one (7 -> 3 -> 2 -> 1 -> 0). 
// If Alice starts removing 1 stone, Bob will remove 4 stones then Alice only can remove 1 stone and finally Bob removes the last one (7 -> 6 -> 2 -> 1 -> 0).

// Example 5:
// Input: n = 17
// Output: false
// Explanation: Alice can't win the game if Bob plays optimally.
 
// Constraints:
// 1 <= n <= 10^5

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ** dp;
public:
    // 1 means alice turn , 0 means bob turn
    bool winner(int n,int turn){
        if(n == 0 && turn == 1){
            return false;
        }

        if(n == 0 && turn == 0){
            return true;
        }

        if(dp[n][turn] != -1){
            return dp[n][turn];
        }

        bool answer = true;
        if(turn == 0){
            for(int i = 1;i<=sqrt(n);i++){
                bool val = winner(n - (i*i),(!turn));
                if(val == false){
                    answer = false;
                    return dp[n][turn] = answer;
                }
            }
            return dp[n][turn] = answer;
        }

        answer = false;
        if(turn == 1){
            for(int i = 1;i<=sqrt(n);i++){
                bool valu = winner(n - (i *i),(!turn));
                if(valu == true){
                    answer = true;
                    return dp[n][turn] = answer;
                }
            }
        }

        return dp[n][turn] = answer;
    }

    bool winnerSquareGame(int n) {
        dp = new int*[n + 1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[2];
            for(int j=0;j<=1;j++){
                dp[i][j] = -1;
            }
        }
        return winner(n,1);
    }
};