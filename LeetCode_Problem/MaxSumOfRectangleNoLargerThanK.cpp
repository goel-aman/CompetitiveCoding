// ## Problem Statement
// 363. Max Sum of Rectangle No Larger Than K
// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

// Example:

// Input: matrix = [[1,0,1],[0,-2,3]], k = 2
// Output: 2 
// Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
//              and 2 is the max number no larger than k (k = 2).
// Note:

// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns?

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int ans = INT_MIN;
        int cols = matrix[0].size();
        // int* arr = new int[rows];
        for(int i=0;i<cols;i++){
             vector<int> arr(rows);
            for(int j=i;j<cols;j++){
                for(int r = 0;r<rows;r++){
                    arr[r] += matrix[r][j];
                }
                set<int> s = {0};
                int current_sum = 0;                
                for(int w=0;w<rows;w++){
                    current_sum += arr[w];
                    // int value = current_sum - k;
                    auto it = s.lower_bound(current_sum - k);
                    if(it != end(s)){
                        ans = max(ans,current_sum - *it); 
                    }
                    if(ans == k){
                        return k;
                    }
                    s.insert(current_sum);
                }
                
            }
        }
        return ans;        
    }
};