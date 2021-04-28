class Solution 
{
    int dp[];
    int n;
    
    
    boolean solve(int arr[],int i,int dp[])
    {
        if(i<0 || i>=n)
            return false;
        
        if(arr[i]==0)
            return true;
        
        // if(dp[i] != -1)
        // {
        //     if(dp[i]==1)
        //         return true;
        //     return false;
        // }
        dp[i] = 1;
        boolean op1;
        boolean op2;
        if(i + arr[i] >= 0 && i + arr[i] < arrLength && dp[i + arr[i]] == -1){
            op1 = solve(arr,i + arr[i],dp);
            if(op1){
                return true;
            }
        }
        
        
        if(i - arr[i] >= 0 && i - arr[i] < arrLength && dp[i - arr[i]] == -1){
            op2 = solve(arr,i-arr[i],dp);
            if(op2){
                return true;
            }
        }
            
        // boolean ans = op1 || op2;
        // if(ans)
        //     dp[i] = 1;
        // else
        //     dp[i] = 2;
        return false;
        
    }
    
    public boolean canReach(int[] arr, int start) 
    {
        n = arr.length;
        dp = new int[n];
        
        for(int i=0;i<n;i++)
            dp[i] = -1;
        return solve(arr,start,dp);
    }
}