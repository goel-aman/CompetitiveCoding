#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[501][501];
public:
    int solve(vector<int>& nums,int i,int j){
        if(i < j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxsum = 0;
        for(int k = i + 1;k<j;k++){
            int left = solve(nums,i,k);
            int right = solve(nums,k,j);
            int current = nums[k] * nums[i] * nums[j];
            maxsum = max(maxsum,left + right + current); 
        }
        return dp[i][j] = maxsum;
    }

    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int length = nums.size(); 
        solve(nums,0,length - 1);      
    }
};