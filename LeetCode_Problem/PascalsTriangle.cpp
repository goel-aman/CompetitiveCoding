// 118. Pascal's Triangle

// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly
//  above it as shown:

// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// Input: numRows = 1
// Output: [[1]]
 
// Constraints:
// 1 <= numRows <= 30Given an integer numRows, return the first numRows
//  of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers 
// directly above it as shown:


// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// Input: numRows = 1
// Output: [[1]]
 
// Constraints:
// 1 <= numRows <= 30
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 1){
            ans.push_back({1});
            return ans;
        } 
        
        if(numRows == 2){
            ans.push_back({1});
            ans.push_back({1,1});
            return ans;
        }
        
        ans.push_back({1});
        ans.push_back({1,1});
        vector<int> prev = {1,1};
        for(int i = 3;i<=numRows;i++){
            vector<int> prevv;
            prevv.push_back({1});
            for(int j=0;j<prev.size() - 1;j++){
                prevv.push_back({prev[j]+prev[j+1]});
            }
            prevv.push_back({1});
            ans.push_back(prevv);
            prev = prevv;
        }
        return ans;
    }
};