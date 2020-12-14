class Solution {
public:
   int dp[501][501];
    int solve(vector<int>& nums,int n,int i,int j){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            return 0;
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int maxm=0;
        for(int k=i+1;k<j;k++){
            int left=solve(nums,n,i,k);
            int right=solve(nums,n,k,j);
            int cost=(nums[k])(nums[i])(nums[j]);
            maxm=max(maxm,left+right+cost);
            dp[i][j]=maxm;
        }
        
        
        return maxm;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
       return solve(nums,n,0,n-1);
    }
};