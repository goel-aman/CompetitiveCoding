#include<bits/stdc++.h>
using namespace std;

// 932. Beautiful Array
// For some fixed N, an array A is beautiful if it is a permutation 
// of the integers 1, 2, ..., N, such that:
// For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].
// Given N, return any beautiful array A.  (It is guaranteed that one exists.)

// Example 1:
// Input: 4
// Output: [2,1,4,3]

// Example 2:
// Input: 5
// Output: [3,1,2,5,4]
 
// Note:
// 1 <= N <= 1000

class Solution {
public:
    vector<int> beautifulArray(int N) {
        if(N == 1){
            return {1};
        }

        vector<int> even = beautifulArray(N/2);
        vector<int> odd = beautifulArray(N - (N/2));

        vector<int> ans;
        for(int i=0;i<(N/2);i++){
            ans.push_back(2*even[i]);
        }

        for(int i=0;i<(N - (N/2));i++){
            ans.push_back(2*odd[i] - 1);
        }
        return ans;
    }
};