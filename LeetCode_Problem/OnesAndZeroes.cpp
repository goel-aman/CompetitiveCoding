#include<bits/stdc++.h>
using namespace std;

// 474. Ones and Zeroes
// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at 
// most m 0's and n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also 
// elements of y.

// Example 1:
// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is 
// {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and 
// {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater
//  than the maximum of 3.

// Example 2:
// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.

// Constraints:
// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100



class Solution {
    int ans = 0;
    int strsLength;
    int dp[601][101][101];
public:
    // at most m zero and n one's.
    int maxForm(vector<string>& strs,int index,int m,int n){

        if(index == strsLength){
            return 0;
        }

        if(dp[index][m][n] != -1){
            return dp[index][m][n];
        }

        // let included the current string
        int totalm = 0;
        int totaln = 0;

        for(int i=0;i<strs[index].length();i++){
            if(strs[index][i] == '0'){
                totalm++;
            }else{
                totaln++;
            }
        }
        int value1 = INT_MIN;
        int value2 = INT_MIN;
        if(totalm <= m && totaln <= n){
            value1 =  1 + maxForm(strs,index + 1,m - totalm,n - totaln);
        }

        // not including the current string;
        value2 = maxForm(strs,index + 1,m,n);
        return dp[index][m][n] = max(value1,value2);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        strsLength = strs.size();
        memset(dp,-1,sizeof(dp));
        return maxForm(strs,0,m,n);
    }
};