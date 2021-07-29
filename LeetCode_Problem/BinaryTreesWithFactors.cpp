#include<bits/stdc++.h>
using namespace std;

// 823. Binary Trees With Factors
// Given an array of unique integers, arr, where 
// each integer arr[i] is strictly greater than 1.

// We make a binary tree using these integers, and
//  each number may be used for any number of times. 
// Each non-leaf node's value should be equal to the 
// product of the values of its children.

// Return the number of binary trees we can make. The
//  answer may be too large so return the answer
//  modulo 109 + 7.

// Example 1:
// Input: arr = [2,4]
// Output: 3
// Explanation: We can make these trees: [2], [4], [4, 2, 2]

// Example 2:
// Input: arr = [2,4,5,10]
// Output: 7
// Explanation: We can make these trees: [2], [4], [5],
//  [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 
// Constraints:
// 1 <= arr.length <= 1000
// 2 <= arr[i] <= 109
// All the values of arr are unique.

class Solution {
    int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int arrLength = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int> um;

        for(int i=0;i<arrLength;i++){
            um[arr[i]]++;
            int value = arr[i];
            for(int j=1;j<=sqrt(value);j++){
                if(arr[i]%j == 0 && um.count(arr[i]/j) > 0 && um.count(j)){
                    if((arr[i]/j) == j){
                        um[arr[i]] += (um[arr[i]/j] * um[j]);
                        continue;
                    }
                    um[arr[i]] += (um[arr[i]/j] * um[j] * 2);
                }
            }
        }
        long long int ans = 0;
        for(auto var : um){
            ans = (ans + var.second)%mod;
        }
        return ans;
    }
};