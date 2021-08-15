#include<bits/stdc++.h>
using namespace std;

// 1131. Maximum of Absolute Value Expression
// Given two arrays of integers with equal lengths, 
// return the maximum value of:
// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
// where the maximum is taken over all 0 <= i, j < arr1.length.

// Example 1:
// Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
// Output: 13

// Example 2:
// Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
// Output: 20

// Constraints:
// 2 <= arr1.length == arr2.length <= 40000
// -10^6 <= arr1[i], arr2[i] <= 10^6


class Solution {
public:
    int getValue(vector<int>& arr){
        int arrLength = arr.size();

        int maxSum = arr[0] , minSum = arr[0];

        for(int i=0;i < arrLength;i++){
            maxSum = max(maxSum,arr[i]);
            minSum = min(minSum,arr[i]);
        }

        return (maxSum - minSum);
    }

    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int arr1Length = arr1.size();

        vector<int> first(arr1Length,0),second(arr1Length,0),third(arr1Length,0),fourth(arr1Length,0);

        for(int i=0;i<arr1Length;i++){
            first[i] = arr1[i] - arr2[i] + i;
            second[i] = arr1[i] - arr2[i] - i;
            third[i] = arr1[i] + arr2[i] + i;
            fourth[i] = arr1[i] + arr2[i] - i;
        }
        int firstValue = getValue(first);
        int secondValue = getValue(second);
        int thirdValue = getValue(third);
        int fourthValue = getValue(fourth);
        int ans = max(firstValue,max(secondValue,max(thirdValue,fourthValue)));
        return ans;
    }
};