#include<bits/stdc++.h>
using namespace std;

//1428. Leftmost Column with at Least a One
// A row-sorted binary matrix means that all elements are 0 or 1 and 
// each row of the matrix is sorted in non-decreasing order.

// Given a row-sorted binary matrix binaryMatrix, return the index 
// (0-indexed) of the leftmost column with a 1 in it. If such an index
//  does not exist, return -1.

// You can't access the Binary Matrix directly. You may only access the 
// matrix using a BinaryMatrix interface:

// BinaryMatrix.get(row, col) returns the element of the matrix at index 
// (row, col) (0-indexed).
// BinaryMatrix.dimensions() returns the dimensions of the matrix as a list
//  of 2 elements [rows, cols], which means the matrix is rows x cols.
// Submissions making more than 1000 calls to BinaryMatrix.get will be judged
//  Wrong Answer. Also, any solutions that attempt to circumvent the judge 
// will result in disqualification.

// For custom testing purposes, the input will be the entire binary matrix 
// mat. You will not have access to the binary matrix directly.

// Example 1:
// Input: mat = [[0,0],[1,1]]
// Output: 0

// Example 2:
// Input: mat = [[0,0],[0,1]]
// Output: 1

// Example 3:
// Input: mat = [[0,0],[0,0]]
// Output: -1

// Constraints:
// rows == mat.length
// cols == mat[i].length
// 1 <= rows, cols <= 100
// mat[i][j] is either 0 or 1.
// mat[i] is sorted in non-decreasing order.

class BinaryMatrix {
    public:
    int get(int row, int col);
    vector<int> dimensions();
};
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */


class Solution {
    BinaryMatrix* store;
public:
    int binarySearch(int start,int end,int row){
        int ans = INT_MAX;
        while(start <= end){
            int midIndex = (start + end) / 2;
            if(store->get(row,midIndex) == 1){
                ans = min(ans,midIndex);
                end = midIndex - 1;
                continue;
            }else{
                start = midIndex + 1;
            }
        }

        return ans;
    }

    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        store = &binaryMatrix;
        vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0];
        int cols = dimensions[1];

        int startCol = 0;
        int endCol = cols - 1;
        int ans = INT_MAX;

        for(int i=0;i<rows;i++){
            if(startCol > endCol){
                break;
            }
            int value = binarySearch(startCol,endCol,i);
            ans = min(ans,value);
            if(value != INT_MAX){
                endCol = min(endCol,value - 1);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};