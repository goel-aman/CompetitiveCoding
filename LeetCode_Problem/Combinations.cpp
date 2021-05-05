#include<bits/stdc++.h>
using namespace std;

// Given two integers n and k, return all possible combinations of k 
// numbers out of the range [1, n].
// You may return the answer in any order.

// Example 1:
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// Example 2:
// Input: n = 1, k = 1
// Output: [[1]]
 
// Constraints:
// 1 <= n <= 20
// 1 <= k <= n


class Solution {
public:
    
    void answer(int n,int k,vector<int> &combination,vector<vector<int>> &res,int start){
        if(k == 0){
            res.push_back(combination);
            return;
        }

        for(int i=start;i<=n - k  + 1;i++){
            combination.push_back(i);
            answer(n,k - 1,combination,res,i + 1);
            combination.pop_back();
        }

        return ;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        vector<vector<int>> result;
        answer(n,k,combination,result,1);
        return result;
    }
};