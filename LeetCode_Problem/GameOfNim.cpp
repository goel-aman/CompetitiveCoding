#include<bits/stdc++.h>
using namespace std;

// 1908. Game of Nim
// Alice and Bob take turns playing a game with 
// Alice starting first.

// In this game, there are n piles of stones. On each
//  player's turn, the player should remove any positive
//  number of stones from a non-empty pile of his or her 
// choice. The first player who cannot make a move loses,
//  and the other player wins.

// Given an integer array piles, where piles[i] is the number 
// of stones in the ith pile, return true if Alice wins, or 
// false if Bob wins.

// Both Alice and Bob play optimally.

// Example 1:
// Input: piles = [1]
// Output: true
// Explanation: There is only one possible scenario:
// - On the first turn, Alice removes one stone from the first pile. piles = [0].
// - On the second turn, there are no stones left for Bob to remove. Alice wins.

// Example 2:
// Input: piles = [1,1]
// Output: false
// Explanation: It can be proven that Bob will always win. One possible scenario is:
// - On the first turn, Alice removes one stone from the first pile. piles = [0,1].
// - On the second turn, Bob removes one stone from the second pile. piles = [0,0].
// - On the third turn, there are no stones left for Alice to remove. Bob wins.

// Example 3:
// Input: piles = [1,2,3]
// Output: false
// Explanation: It can be proven that Bob will always win. One possible scenario is:
// - On the first turn, Alice removes three stones from the third pile. piles = [1,2,0].
// - On the second turn, Bob removes one stone from the second pile. piles = [1,1,0].
// - On the third turn, Alice removes one stone from the first pile. piles = [0,1,0].
// - On the fourth turn, Bob removes one stone from the second pile. piles = [0,0,0].
// - On the fifth turn, there are no stones left for Alice to remove. Bob wins.

// Constraints:
// n == piles.length
// 1 <= n <= 7
// 1 <= piles[i] <= 7

// Follow-up: Could you find a linear time solution? Although the linear time
//  solution may be beyond the scope of an interview, it could be interesting 
// to know.


class Solution {
    int pilesLength;
    unordered_map<string,bool> store;
public:
    // chance == 0 -> alice
    // chance == 1 -> bob
    string generate(vector<int> piles){
        sort(piles.begin(),piles.end());
        
        string value = "";
        for(int i=0;i<pilesLength;i++){
            value += to_string(piles[i]);
            value += ";";
        }
        
        return value;
    }
    
    bool solve(vector<int>& piles,int chance){
        
        string value = generate(piles);
        value += to_string(chance);
        
        if(store.count(value) > 0){
            return store[value];
        }
        
        
        bool allzero = true;
        for(int i=0;i<pilesLength;i++){
            if(piles[i] > 0){
                allzero = false;
                break;
            }
        }

        if(allzero){
            store[value] =  ((chance == 0) ? false : true);
            return (chance == 0) ? false : true;
        }
        
        for(int i=0;i<pilesLength;i++){
            if(piles[i] == 0){
                continue;
            }

            for(int j=1;j<= piles[i];j++){
                piles[i] -= j;
                bool valuee = solve(piles,!chance);
                if(chance == 0 && valuee == true){
                    piles[i] += j;
                    store[value] = true;
                    return true;
                }
                if(chance == 1 && valuee == false){
                    piles[i] += j;
                    store[value] = false;
                    return false;
                }
                piles[i] += j;
            }
        }
        if(chance == 0){
            store[value] = false;
            return false;
        }
        store[value] = true;
        return true;
    }

    bool nimGame(vector<int>& piles) {
        store.clear();
        pilesLength = piles.size();
        return solve(piles,0);
    }
};