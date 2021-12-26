#include<bits/stdc++.h>
using namespace std;

// 119. Pascal's Triangle II
// Given an integer rowIndex, return the rowIndexth 
// (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of 
// the two numbers directly above it as shown:

// Example 1:
// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:
// Input: rowIndex = 0
// Output: [1]

// Example 3:
// Input: rowIndex = 1
// Output: [1,1]
 
// Constraints:
// 0 <= rowIndex <= 33
 
// Follow up: Could you optimize your algorithm to use
//  only O(rowIndex) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        prev.push_back(1);
        
        while(rowIndex > 0){
            vector<int> current;
            current.push_back(1);
            int length = prev.size();
            for(int i=0;i<length - 1;i++){
                int number = prev[i] + prev[i + 1];
                current.push_back(number);
            }
            current.push_back(1);
            prev = current;
            rowIndex--;
        }
        return prev;
    }
};