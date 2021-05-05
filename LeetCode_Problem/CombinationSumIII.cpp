// 216. Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice,
//  and the combinations may be returned in any order.

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:
// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.

// Example 4:
// Input: k = 3, n = 2
// Output: []
// Explanation: There are no valid combinations.

// Example 5:
// Input: k = 9, n = 45
// Output: [[1,2,3,4,5,6,7,8,9]]
// Explanation:
// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
// ​​​​​​​There are no other valid combinations.
 
// Constraints:
// 2 <= k <= 9
// 1 <= n <= 60

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void combinationSum(int k,int n,vector<int>& combination,set<vector<int>> &res,int val){
        if(k == 0 && n == 0){
            res.insert(combination);
        }
        
        
        if(k <= 0 && n != 0){
            return ;
        }
        
        if(val > 9){
            return ;
        }
        
        if(n >= val){
            combination.push_back(val);
            combinationSum(k - 1,n - val,combination,res,val + 1);
            combination.pop_back();
        }
        
        combinationSum(k,n,combination,res,val + 1);
        return ;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>>  res;
        vector<int> combination;
        combinationSum(k,n,combination,res,1);
        vector<vector<int>> ans;
        for(auto m : res){
            ans.push_back(m);
        }
        return ans;
    }
};