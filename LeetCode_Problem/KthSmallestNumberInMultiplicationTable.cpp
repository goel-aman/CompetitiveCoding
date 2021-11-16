#include<bits/stdc++.h>
using namespace std;

// 668. Kth Smallest Number in Multiplication Table
// Nearly everyone has used the Multiplication Table. 
// The multiplication table of size m x n is an 
// integer matrix mat where mat[i][j] == i * j
//  (1-indexed).

// Given three integers m, n, and k, return the kth 
// smallest element in the m x n multiplication table.

// Example 1:
// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: The 5th smallest number is 3.

// Example 2:
// Input: m = 2, n = 3, k = 6
// Output: 6
// Explanation: The 6th smallest number is 6.
 
// Constraints:
// 1 <= m, n <= 3 * 104
// 1 <= k <= m * n

class Solution {
    int rows,cols;
public:
    int totalNumber(int value){
        int ans = 0;
        for(int i=1;i<=rows;i++){
            ans += min(value/i,cols);
        }
        return ans;
    }

    int findKthNumber(int m, int n, int k) {
        rows = m, cols = n;
        int ans = -1;
        int start = 1, end = (m * n);
        int mid = (start + end)/2;
        while(start <= end){
            mid = (start + end)/2;
            int value = totalNumber(mid);
            if(value >= k){
                ans = mid;
                end = mid - 1;
                continue;
            }

            if(value < k){
                start = mid + 1;
                continue;
            }
        }
        return ans;
    }
};