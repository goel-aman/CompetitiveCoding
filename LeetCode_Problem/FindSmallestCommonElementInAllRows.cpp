#include<bits/stdc++.h>
using namespace std;

// 1198. Find Smallest Common Element in All Rows
// Given an m x n matrix mat where every row is sorted in 
// strictly increasing order, return the smallest common 
// element in all rows.
// If there is no common element, return -1.

// Example 1:
// Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
// Output: 5

// Example 2:
// Input: mat = [[1,2,3],[2,3,4],[2,3,5]]
// Output: 2
 
// Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 500
// 1 <= mat[i][j] <= 104
// mat[i] is sorted in strictly increasing order.

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        unordered_map<int,int> frequency;
        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                frequency[mat[j][i]]++;
                if(frequency[mat[j][i]] == rows){
                    return mat[j][i];
                }
            }
        }

        return -1;
    }
};