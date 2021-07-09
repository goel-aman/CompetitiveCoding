#include<bits/stdc++.h>
using namespace std;

// 473. Matchsticks to Square
// You are given an integer array matchsticks where matchsticks[i]
//  is the length of the ith matchstick. You want to use all the 
// matchsticks to make one square. You should not break any stick, 
// but you can link them up, and each matchstick must be used
//  exactly one time.

// Return true if you can make this square and false otherwise.

// Example 1:
// Input: matchsticks = [1,1,2,2,2]
// Output: true
// Explanation: You can form a square with length 2, one side of the
//  square came two sticks with length 1.

// Example 2:
// Input: matchsticks = [3,3,3,3,4]
// Output: false
// Explanation: You cannot find a way to form a square with all 
// the matchsticks.
 
// Constraints:
// 1 <= matchsticks.length <= 15
// 1 <= matchsticks[i] <= 108

class Solution {
    int matchsticksLength;
public:
    bool checkSquare(vector<int>& matchsticks,int index,vector<int> &elements,int &target){
        if(index == matchsticksLength){
            bool ans = true;
            for(auto var : elements){
                if(var != target){
                    ans = false;
                    break;
                }
            }
            return ans;
        }

        for(int i=0;i<4;i++){
            elements[i] += matchsticks[index];
            if(elements[i] > target){
                elements[i] -= matchsticks[index];
                continue;
            }

            bool value = checkSquare(matchsticks,index + 1,elements,target);
            if(value == true){
                elements[i] -= matchsticks[index];
                return true;
            }

            elements[i] -= matchsticks[index];
        }
        return false;
    }
        
    bool makesquare(vector<int>& matchsticks) {
        matchsticksLength = matchsticks.size();
        vector<int> elements(4,0);
        
        int sum = 0;
        
        for(auto var : matchsticks){
            sum += var;
        }
        
        if(sum%4 != 0){
            return false;
        }
        int val = (sum / 4);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return checkSquare(matchsticks,0,elements,val);
    }
};