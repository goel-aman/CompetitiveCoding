#include<bits/stdc++.h>
using namespace std;

// 1213. Intersection of Three Sorted Arrays
// Given three integer arrays arr1, arr2 and arr3 sorted in strictly 
// increasing order, return a sorted array of only the integers that
//  appeared in all three arrays.

// Example 1:
// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
// Output: [1,5]
// Explanation: Only 1 and 5 appeared in the three arrays.

// Example 2:
// Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870],
//  arr3 = [521,682,1337,1395,1764]
// Output: []
 
// Constraints:
// 1 <= arr1.length, arr2.length, arr3.length <= 1000
// 1 <= arr1[i], arr2[i], arr3[i] <= 2000

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        
        unordered_set<int> second;
        unordered_set<int> third;
        
        int arr2Length = arr2.size();
        int arr3Length = arr3.size();
        int arr1Length = arr1.size();
        for(int i=0;i<arr2Length;i++){
            second.insert(arr2[i]);
        }
        
        for(int i=0;i<arr3Length;i++){
            third.insert(arr3[i]);
        }
        
        for(int i=0;i<arr1Length;i++){
            if(second.count(arr1[i]) > 0 && third.count(arr1[i]) > 0){
                ans.push_back(arr1[i]);
            }
        }
        return ans;
    }
};