#include<bits/stdc++.h>
using namespace std;

// Valid Mountain Array
// Given an array of integers arr, return true if and only if it is a valid mountain array.
// Recall that arr is a mountain array if and only if:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < A[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Example 1:
// Input: arr = [2,1]
// Output: false

// Example 2:
// Input: arr = [3,5,5]
// Output: false

// Example 3:
// Input: arr = [0,3,2,1]
// Output: true
 
// Constraints:
// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int length = arr.size();
        if(length < 3){
            return false;
        }
        int ans = true;
        int prev = arr[0];
        int i =1;
        for(i=1;i<length;i++){
            if(i == 1 && arr[i] <= prev){
                return false;
            }
            if(arr[i] > prev){
                prev = arr[i];
                continue;
            }
            break;
        }
        if(i == length ){
            return false;
        }
        if(i == length - 1 && prev == arr[i]){
            return false;
        }
        
        if(i == length - 1 && prev > arr[i]){
            return true;
        }
        prev = arr[i];
        i++;
        for(;i<length;i++){
            if(arr[i]< prev){
                prev = arr[i];
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};