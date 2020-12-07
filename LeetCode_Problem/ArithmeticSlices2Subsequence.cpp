// 446. Arithmetic Slices II - Subsequence
// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequences:

// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.

// 1, 1, 2, 5, 7
 
// A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

// A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.

// The function should return the number of arithmetic subsequence slices in the array A.

// The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.

 
// Example:

// Input: [2, 4, 6, 8, 10]

// Output: 7

// Explanation:
// All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& A) {
        long long int length = A.size();
        long long int ans = 0;
        unordered_map<long long int,long long int> * um = new unordered_map<long long int,long long int>[length];
        for(long long int i=1;i<length;i++){
            for(long long int j = i - 1 ;j>=0;j--){
                long long int diff = (long long int)A[i] - (long long int)A[j];
                if(um[j].count(diff) > 0)
                {
                    ans += um[j][diff];
                    um[i][diff] += um[j][diff] + 1;
                }
                else{
                    um[i][diff]++;
                }
            }
        }
        return (int)ans;
    }
};