#include<bits/stdc++.h>
using namespace std;

// 1218. Longest Arithmetic Subsequence of Given Difference
// Given an integer array arr and an integer difference, return
//  the length of the longest subsequence in arr which is an
//  arithmetic sequence such that the difference between 
// adjacent elements in the subsequence equals difference.

// A subsequence is a sequence that can be derived from arr by
//  deleting some or no elements without changing the order 
// of the remaining elements.

// Example 1:
// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].

// Example 2:
// Input: arr = [1,3,5,7], difference = 1
// Output: 1
// Explanation: The longest arithmetic subsequence is any single element.

// Example 3:
// Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
// Output: 4
// Explanation: The longest arithmetic subsequence is [7,5,3,1].

// Constraints:
// 1 <= arr.length <= 10^5
// -104 <= arr[i], difference <= 10%4

class Solution {
    int diff;
    int arrLength;
    int dp[100001];
public:
    int longest(vector<int>& arr,int index){
        if(index == arrLength){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }

        int ans = 1;
        int value = 0;
        for(int i=index + 1;i < arrLength;i++){
            if(arr[i] == (arr[index] + diff))
            {
                value = max(value,longest(arr,i));
            }
        }
        
        return dp[index] = (value + ans);  
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        arrLength = arr.size();
        unordered_map<int,int> um;
        int ans = 0;
        for(int i=0;i<arrLength;i++){
            if(um.count(arr[i] - difference) > 0){
                um[arr[i]] = um[arr[i] - difference] + 1;
                ans = max(ans,um[arr[i]]);
            }else{
                um[arr[i]] = 1;
                ans = max(ans,um[arr[i]]);
            }
        }
        return ans;
    }
};