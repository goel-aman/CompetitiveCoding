#include<bits/stdc++.h>
using namespace std;

// 370. Range Addition
// You are given an integer length and an array updates where
// updates[i] = [startIdxi, endIdxi, inci].
// You have an array arr of length length with all zeros, and 
// you have some operation to apply on arr. In the ith operation, 
// you should increment all the elements arr[startIdxi], 
// arr[startIdxi + 1], ..., arr[endIdxi] by inci.
// Return arr after applying all the updates.

// Example 1:
// Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]

// Example 2:
// Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
// Output: [0,-4,2,2,2,4,4,-4,-4,-4]
 
// Constraints:
// 1 <= length <= 105
// 0 <= updates.length <= 104
// 0 <= startIdxi <= endIdxi < length
// -1000 <= inci <= 1000

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret(length,0);
        
        for(int i=0;i<updates.size();i++){
            int startIndex = updates[i][0], endIndex = updates[i][1], increment = updates[i][2];
            
            ret[startIndex] += increment;
            if(endIndex + 1 < length){
                ret[endIndex + 1] -= increment;
            }
        }
        int value = 0;
        for(int i=0;i<length;i++){
            value += ret[i];
            ret[i] = value;
        }
        return ret;
    }
};