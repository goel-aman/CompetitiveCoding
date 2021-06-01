#include<bits/stdc++.h>
using namespace std;

// 1296. Divide Array in Sets of K Consecutive Numbers

// Given an array of integers nums and a positive integer k, find
//  whether it's possible to divide this array into sets of k
//  consecutive numbers
// Return True if it is possible. Otherwise, return False.

// Example 1:
// Input: nums = [1,2,3,3,4,4,5,6], k = 4
// Output: true
// Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

// Example 2:
// Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
// Output: true
// Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

// Example 3:
// Input: nums = [3,3,2,2,1,1], k = 3
// Output: true

// Example 4:
// Input: nums = [1,2,3,4], k = 3
// Output: false
// Explanation: Each array should be divided in subarrays of size 3.
 
// Constraints:
// 1 <= k <= nums.length <= 105
// 1 <= nums[i] <= 109



class elem{
    public:
    int value;
    int frequency;
};

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<elem> vec;
        for(auto element : m){
            vec.push_back({element.first,element.second});
        }
        bool ans = true;
        int length = vec.size();
        for(int i=0;i<length;i++){
            
            if(vec[i].frequency == 0){
                continue;
            }
            
            int minFreq = vec[i].frequency;
            int prev = vec[i].value;
            for(int j = i;j<= i + k - 1;j++){
                if(j >= length){
                    return false;
                }
                if(vec[j].value != prev){
                    return false;
                }

                if(vec[j].frequency < minFreq){
                    return false;
                }
                vec[j].frequency -= minFreq;
                prev = vec[j].value + 1;
            }
        }
        return ans;
    }      
};