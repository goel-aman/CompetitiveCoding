#include<bits/stdc++.h>
using namespace std;

// 1524. Number of Sub-arrays With Odd Sum
// Given an array of integers arr. Return the number
//  of sub-arrays with odd sum.
// As the answer may grow large, the answer must be
//  computed modulo 10^9 + 7.

// Example 1:
// Input: arr = [1,3,5]
// Output: 4
// Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
// All sub-arrays sum are [1,4,9,3,8,5].
// Odd sums are [1,9,3,5] so the answer is 4.

// Example 2:
// Input: arr = [2,4,6]
// Output: 0
// Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
// All sub-arrays sum are [2,6,12,4,10,6].
// All sub-arrays have even sum and the answer is 0.

// Example 3:
// Input: arr = [1,2,3,4,5,6,7]
// Output: 16

// Example 4:
// Input: arr = [100,100,99,99]
// Output: 4

// Example 5:
// Input: arr = [7]
// Output: 1
 
// Constraints:
// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 100

class element{
    public:
    int oddEnding;
    int evenEnding;

    element(){
        oddEnding = 0;
        evenEnding = 0;
    }
};

class Solution {
    int mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int arrLength = arr.size();
        vector<element> vec(arrLength + 1);
        vec[1].evenEnding = ((arr[0]%2 == 0) ? 1 : 0);
        vec[1].oddEnding = ((arr[0]%2 == 1) ? 1 : 0);
        for(int i=1;i<arrLength;i++){
            if(arr[i]%2 == 0){
                vec[i + 1].evenEnding = (vec[i].evenEnding + 1)%mod;
                vec[i + 1].oddEnding = (vec[i].oddEnding)%mod; 
            }else{
                vec[i + 1].evenEnding = (vec[i].oddEnding)%mod;
                vec[i + 1].oddEnding = (vec[i].evenEnding + 1)%mod;
            }
        }
        
        int ans = 0;
        for(int i=1;i<=arrLength;i++){
            ans = (ans + (vec[i].oddEnding)%mod)%mod;
        }
        return ans;
    }
};