
// Alternate Solution
// public class Solution {
//     Integer[][] memo = new Integer[1001][1001];
//     public int kInversePairs(int n, int k) {
//         if (n == 0)
//             return 0;
//         if (k == 0)
//             return 1;
//         if (memo[n][k] != null)
//             return memo[n][k];
//         int inv = 0;
//         for (int i = 0; i <= Math.min(k, n - 1); i++)
//             inv = (inv + kInversePairs(n - 1, k - i)) % 1000000007;
//         memo[n][k] = inv;
//         return inv;
//     }
// }



// class Solution {
//     long int mod = 1000000007;
    
// public:
//     int kInversePairs(int n, int k) {
        
//         if(k > (n*(n - 1) / 2) || k < 0){
//             return 0;
//         }
//         if(k == 0 || k == ((n*(n - 1))/ 2)){
//             return 1;
//         }
        
//         long ** dp = new long*[n+1];
//         for(int i=0;i<=n;i++){
//             dp[i] = new long[k + 1];
//             for(int j=0;j<=k;j++){
//                 dp[i][j] = 0;
//             }
//         }
        
//         dp[2][0] = 1;
//         dp[2][1] = 1;
//         for(int i=3;i<=n;i++){
//             dp[i][0] = 1;
//             for(int j=1;j<= min((i*(i - 1)/ 2),k);j++){
//                 dp[i][j] = dp[i][j - 1] + dp[i -1][j];
//                 if(j >= i){
//                     dp[i][j] -= dp[i - 1][j - i];
//                 }
//                 dp[i][j] = (dp[i][j] + mod)%mod;
//             }
//         }
//         return (int) dp[n][k];
//     }
// };



