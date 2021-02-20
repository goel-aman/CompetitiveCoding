// 1402. Reducing Dishes
// A chef has collected data on the satisfaction level of his n dishes. 
// Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook
//  that dish including previous dishes multiplied by its satisfaction 
// level  i.e.  time[i]*satisfaction[i]

// Return the maximum sum of Like-time coefficient that the chef can 
// obtain after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some 
// dishes to get this maximum value.

// Example 1:
// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total 
// Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each 
// dish is prepared in one unit of time.

// Example 2:
// Input: satisfaction = [4,3,2]
// Output: 20
// Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

// Example 3:
// Input: satisfaction = [-1,-4,-5]
// Output: 0
// Explanation: People don't like the dishes. No dish is prepared.


// Example 4:
// Input: satisfaction = [-2,5,-1,0,3,-3]
// Output: 35
 
// Constraints:
// n == satisfaction.length
// 1 <= n <= 500
// -10^3 <= satisfaction[i] <= 10^3
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // unordered_map<string,int> um;
    int dp[501][501];
public:
    Solution(){
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j] = -1;
            }
        }
    }
    
    int maxSatisfactionx(vector<int>& satisfaction, int value,int index){
        if(index >= satisfaction.size()){
            return 0;
        }
        
        if(dp[value][index] != -1){
            return dp[value][index];
        }

        int letsTakeIt = maxSatisfactionx(satisfaction,value + 1,index + 1) + (value * satisfaction[index]);
        int letsNotTakeIt = maxSatisfactionx(satisfaction,value,index + 1);

        return dp[value][index] = max(letsTakeIt,letsNotTakeIt);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        return maxSatisfactionx(satisfaction,1,0);        
    }
};