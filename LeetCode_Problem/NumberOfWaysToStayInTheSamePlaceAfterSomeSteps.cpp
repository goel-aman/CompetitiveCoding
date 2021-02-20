// 1269. Number of Ways to Stay in the Same Place After Some Steps

// You have a pointer at index 0 in an array of size arrLen. At each step,
//  you can move 1 position to the left, 1 position to the right in the array
//  or stay in the same place  (The pointer should not be placed outside the 
// array at any time).

// Given two integers steps and arrLen, return the number of ways such that 
// your pointer still at index 0 after exactly steps steps.

// Since the answer may be too large, return it modulo 10^9 + 7.

// Example 1:
// Input: steps = 3, arrLen = 2
// Output: 4
// Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
// Right, Left, Stay
// Stay, Right, Left
// Right, Stay, Left
// Stay, Stay, Stay

// Example 2:
// Input: steps = 2, arrLen = 4
// Output: 2
// Explanation: There are 2 differents ways to stay at index 0 after 2 steps
// Right, Left
// Stay, Stay

// Example 3:
// Input: steps = 4, arrLen = 2
// Output: 8

// Constraints:
// 1 <= steps <= 500
// 1 <= arrLen <= 10^6


#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,int> um;
public:
    // 0 stay
    // 1 right
    // 2 left
    int ways(int stepsLeft, int arrLen, int currentPosition){
        if(stepsLeft == 0){
            if(currentPosition == 0){
                return 1;
            }else{
                return 0;
            }
        }

        string s;
        s += to_string(stepsLeft) + ";" + to_string(currentPosition);
        if(um.count(s) > 0){
            return um[s];
        }

        int forward = 0;
        if(currentPosition + 1 < arrLen){
            forward = ways(stepsLeft - 1,arrLen,currentPosition + 1);
        }
        int backward = 0;
        if(currentPosition - 1 >= 0){
            backward = ways(stepsLeft-1,arrLen,currentPosition - -1);
        }

        int stay =0;
        stay = ways(stepsLeft - 1, arrLen,currentPosition);
        int ans = forward + backward + stay;
        um[s] = ans;
        return ans;
    }

    int numWays(int steps, int arrLen) {
        return ways(steps,arrLen,0);
    }
};
