#include<bits/stdc++.h>
using namespace std;

// 760. Find Anagram Mappings
// You are given two integer arrays nums1 and nums2 where nums2 is
//  an anagram of nums1. Both arrays may contain duplicates.
// Return an index mapping array mapping from nums1 to nums2 where
//  mapping[i] = j means the ith element in nums1 appears in nums2 
// at index j. If there are multiple answers, return any of them.

// An array a is an anagram of an array b means b is made by randomizing
//  the order of the elements in a.

// Example 1:
// Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
// Output: [1,4,3,2,0]
// Explanation: As mapping[0] = 1 because the 0th element of nums1 appears 
// at nums2[1], and mapping[1] = 4 because the 1st element of nums1 appears
//  at nums2[4], and so on.

// Example 2:
// Input: nums1 = [84,46], nums2 = [84,46]
// Output: [0,1]
 
// Constraints:
// 1 <= nums1.length <= 100
// nums2.length == nums1.length
// 0 <= nums1[i], nums2[i] <= 105
// nums2 is an anagram of nums1.

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>> indexPanel;
        
        int length = nums2.size();
        
        for(int i=0;i<length;i++){
            indexPanel[nums2[i]].push_back(i);    
        }
        
        vector<int> ans;
        
        for(int i=0;i<length;i++){
            for(int j=0;j<indexPanel[nums1[i]].size();j++){
                if(indexPanel[nums1[i]][j] != -1){
                    ans.push_back(indexPanel[nums1[i]][j]);
                    indexPanel[nums1[i]][j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};