#include<bits/stdc++.h>
using namespace std;

// 1053. Previous Permutation With One Swap
// Given an array of positive integers arr (not necessarily 
// distinct), return the lexicographically largest permutation
//  that is smaller than arr, that can be made with exactly one
//  swap (A swap exchanges the positions of two numbers arr[i]
//  and arr[j]). If it cannot be done, then return the same array.

// Example 1:
// Input: arr = [3,2,1]
// Output: [3,1,2]
// Explanation: Swapping 2 and 1.

// Example 2:
// Input: arr = [1,1,5]
// Output: [1,1,5]
// Explanation: This is already the
//  smallest permutation.

// Example 3:
// Input: arr = [1,9,4,6,7]
// Output: [1,7,4,6,9]
// Explanation: Swapping 9 and 7.

// Example 4:
// Input: arr = [3,1,1,3]
// Output: [1,3,1,3]
// Explanation: Swapping 1 and 3.
 
// Constraints:
// 1 <= arr.length <= 104
// 1 <= arr[i] <= 104

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int arrLength = arr.size();
        int breakPoint = -1;
        for(int i=arrLength - 1;i > 0;i--){
            if(arr[i - 1] > arr[i]){
                breakPoint = i - 1;
                break;
            }
        }
        if(breakPoint == -1){
            return arr;
        }
        int nextStart = breakPoint + 1;
        for(int i = nextStart;i<arrLength;i++){
            if(arr[breakPoint] > arr[i] && arr[i] > arr[nextStart]){
                nextStart = i;
            }
        }

        swap(arr[breakPoint],arr[nextStart]);
        return arr;
    }
};