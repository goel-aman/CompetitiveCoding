#include<bits/stdc++.h>
using namespace std;

// 386. Lexicographical Numbers

// Given an integer n, return all the numbers in the 
// range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time
//  and uses O(1) extra space. 

// Example 1:
// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

// Example 2:
// Input: n = 2
// Output: [1,2]
 
// Constraints:
// 1 <= n <= 5 * 104

class Solution {
public:
    void order(int n,int i,vector<int>& ans){
        if(i > n){
            return ;
        }

        ans.push(i);
        for(int j=0;j<=9;j++){
            order(n,i*10 + j,ans);
        }
        return ;
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        order(n,1,ans);
        return ans;
    }
};