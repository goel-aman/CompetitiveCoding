#include<bits/stdc++.h>
using namespace std;

// 930. Binary Subarrays With Sum

// In an array A of 0s and 1s, how many non-empty subarrays have sum S?

// Example 1:
// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
 
// Note:
// A.length <= 30000
// 0 <= S <= A.length
// A[i] is either 0 or 1.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ALength = A.size();
        unordered_map<int,int> um;
        um[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<ALength;i++){
            sum += A[i];
            if(um.count(sum - S) > 0){
                ans += um[sum - S];
            }
            um[sum]++;
        }
        return ans;
    }
};