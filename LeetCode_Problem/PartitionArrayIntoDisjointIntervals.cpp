#include<bits/stdc++.h>
using namespace std;

// 915. Partition Array into Disjoint Intervals
// Given an array nums, partition it into two (contiguous)
//  subarrays left and right so that:

// Every element in left is less than or equal to every
//  element in right.
// left and right are non-empty.
// left has the smallest possible size.
// Return the length of left after such a partitioning.  It
//  is guaranteed that such a partitioning exists.

// Example 1:
// Input: nums = [5,0,3,8,6]
// Output: 3
// Explanation: left = [5,0,3], right = [8,6]

// Example 2:
// Input: nums = [1,1,1,0,6,12]
// Output: 4
// Explanation: left = [1,1,1,0], right = [6,12]

// Note:
// 2 <= nums.length <= 30000
// 0 <= nums[i] <= 106
// It is guaranteed there is at least one way
//  to partition nums as described.

class element{
    public:
    int value;
    int index;
};

bool compare(element& a,element& b)
{
    if(a.value < b.value){
        return true;
    }
    
    if(a.value == b.value){
        if(a.index < b.index){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int numsLength = nums.size();
        vector<element> vec(numsLength);
        for(int i=0;i<numsLength;i++){
            vec[i].value = nums[i];
            vec[i].index = i;
        }
        sort(vec.begin(),vec.end(),compare);
        int maxIndex = -1;
        for(int i=0;i<numsLength;i++){
            maxIndex = max(maxIndex,vec[i].index);
            if(maxIndex == i){
                break;
            }
        }

        return maxIndex + 1;
    }
};