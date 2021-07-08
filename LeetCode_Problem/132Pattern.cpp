#include<bits/stdc++.h>
using namespace std;

// 132 Pattern
// Given an array of n integers nums, a 132 pattern is a subsequence of
// three integers nums[i], nums[j] and nums[k] such that i < j < k and
// nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in 
// nums, otherwise, return false.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.

// Example 2:
// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

// Example 3:
// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the 
// sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 
// Constraints:
// n == nums.length
// 1 <= n <= 2 * 105
// -109 <= nums[i] <= 109


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int numsLength = nums.size();
        stack<int> st;
        vector<int> vec(numsLength);
        vec[0] = nums[0] ;
        
        for(int i=1;i<numsLength;i++){
            vec[i] = min(nums[i - 1],vec[i - 1]);
        }

        st.push(nums[numsLength - 1]);
        for(int i=numsLength - 2;i>=1;i--){
            int jthElement = nums[i];
            int ithElement = vec[i];

            while(!st.empty() && st.top() <= ithElement){
                st.pop();
            }

            if(!st.empty() && st.top() < jthElement && ithElement < st.top() && jthElement > ithElement){
                return true;
            }

            st.push(nums[i]);
        }
        return false;
    }
};
