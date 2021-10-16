#include<bits/stdc++.h>
using namespace std;

// Least Number of Unique Integers after K Removals
// Given an array of integers arr and an integer k. Find the least
//  number of unique integers after removing exactly k elements.

// Example 1:
// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.

// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s.
//  1 and 3 will be left.
 
// Constraints:
// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 10^9
// 0 <= k <= arr.length

bool compare(pair<int,int> &first,pair<int,int> &second){
    if(first.first < second.first){
        return true;
    }

    return false;
}

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int arrLength = arr.size();
        unordered_map<int,int> frequency;
        for(int i=0;i<arrLength;i++){
            frequency[arr[i]]++;
        }
        vector<pair<int,int>> ElementCount;
        for(auto &var : frequency){
            ElementCount.push_back({var.second,var.first});
        }
        sort(ElementCount.begin(),ElementCount.end(),compare);
        int frequencyLength = frequency.size();
        int tempk = k,index = frequencyLength;
        for(int i=0;i<frequencyLength;i++){
            if(ElementCount[i].first > tempk){
                index = i;
                break;
            }else{
                tempk -= ElementCount[i].first;
            }
        }
        return (frequencyLength - index);
    }
};