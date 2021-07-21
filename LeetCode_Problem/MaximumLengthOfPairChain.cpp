#include<bits/stdc++.h>
using namespace std;

// 646. Maximum Length of Pair Chain
// You are given an array of n pairs pairs
//  where pairs[i] = [lefti, righti] and lefti < righti.
// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c.
//  A chain of pairs can be formed in this fashion.
// Return the length longest chain which can be formed.
// You do not need to use up all the given intervals.
//  You can select pairs in any order.

// Example 1:
// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].

// Example 2:
// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 
// Constraints:
// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti < 1000

bool compare(vector<int>& a,vector<int>& b){
    if(a[1] < b[1]){
        return true;
    }

    if(a[1] == b[1]){
        if(a[0] < b[0])
        {
            return true;
        }
    }

    return false;
}

class Solution {
    int dp[1001];
    int pairsLength;
public:
    int findLongest(vector<vector<int>>& pairs,int index){
        if(index >= pairsLength){
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        int value = 0;
        for(int i=index + 1;i<pairsLength;i++){
            if(pairs[index][1] < pairs[i][0]){
                value = max(value,findLongest(pairs,i));
            }
        }

        return (dp[index] = value + 1);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        pairsLength = pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end(),compare);
        int ans = INT_MIN;
        for(int i=0;i<pairsLength;i++){
            ans = max(ans,findLongest(pairs,i));
        }    
        return ans;
    }
};