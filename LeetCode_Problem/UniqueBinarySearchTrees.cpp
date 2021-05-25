#include<bits/stdc++.h>
using namespace std;

// 96. Unique Binary Search Trees

// Given an integer n, return the number of structurally unique BST's
//  (binary search trees) which has exactly n nodes of unique values
//  from 1 to n.

// Example 1:
// Input: n = 3
// Output: 5

// Example 2:
// Input: n = 1
// Output: 1
 
// Constraints:
// 1 <= n <= 19

class Solution {
    unordered_map<int,int> um;
public:
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        if(um.count(n)){
            return um[n];
        }
        int ans = 0;

        for(int i=1;i<=n;i++){
            int val1 = numTrees(i - 1);
            int val2 = numTrees(n - i);
            ans += (val1 * val2);
        }
        return um[n] = ans;
    }
};