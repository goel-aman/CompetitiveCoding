// 378. Kth Smallest Element in a Sorted Matrix

// Given an n x n matrix where each of the rows and columns are sorted in 
// ascending order, return the kth smallest element in the matrix.
// Note that it is the kth smallest element in the sorted order, not the 
// kth distinct element.

// Example 1:
// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

// Example 2:
// Input: matrix = [[-5]], k = 1
// Output: -5
 
// Constraints:
// n == matrix.length
// n == matrix[i].length
// 1 <= n <= 300
// -109 <= matrix[i][j] <= 109
// All the rows and columns of matrix are guaranteed to be sorted in non-degreasing order.
// 1 <= k <= n2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLessThan(int mid,vector<vector<int>>& matrix){
        /*
            return type : int
            description: the function is going to return the count of number of element in matrix whose 
            value is less than or equal to k.
        */

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = rows - 1;
        int col = 0;
        int count = 0;
        while(row >= 0 && col < cols){
            if(matrix[row][col] <= mid){
                count += (row + 1);
                col++;
                continue;
            }

            if(matrix[row][col] > mid){
                row -= 1;
                continue;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix.size();
        int low = matrix[0][0];
        int high = matrix[rows - 1][cols - 1];
        int answer;
        while(low <= high){
            int mid = ((low + high) / 2);
            int val = countLessThan(mid,matrix);
            if(val >= k){
                answer = mid;
                high = mid - 1;
                continue;
            }

            if(val < k){
                low = mid + 1;
                continue;
            }
        }
        return answer;
    }
};