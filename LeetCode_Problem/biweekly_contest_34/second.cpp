#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

class Solution {
public:
    int dp[100005][4];

    int ans(string s,int &one_count,int divide_part){
        if(divide_part == 1){
            int required_ones = one_count / 3;
            int current_one_count = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] == '1'){
                    current_one_count++;
                }
            }
            if(current_one_count == required_ones){
                dp[s.size()][divide_part] = 1;
                return 1;
            }
            dp[s.size()][divide_part] = 0;
            return 0;
        }
        if(dp[s.size()][divide_part] != -1){
            return dp[s.size()][divide_part];
        }
        int final_ans = 0;
        int required_ones = one_count / 3;
        int current_one_count  = 0;
        int i =0;
        for(i=0;i<s.size();i++){
            if(s[i] == '1'){
                current_one_count ++;
            }
            if(current_one_count == required_ones){
                break;
            }
        }
        final_ans += ans(s.substr(i+1),one_count,divide_part - 1);
        final_ans = final_ans % MOD;
        int j=1;
        for(j = 1;s[i+j] != '1' && i+j < s.size()- 1;j++){
            final_ans += ans(s.substr(i+j+1),one_count,divide_part - 1);
            final_ans = final_ans % MOD;
        }
        dp[s.size()][divide_part] = final_ans % MOD;
        return final_ans%MOD;
    }
    ///"00000000"
    // ans 21

    int numWays(string s) {
        int length = s.size();
        int one_count = 0;
        for(int i=0;i<length;i++){
            if(s[i] == '1'){
                one_count++;
            }
        }
        if(one_count%3 != 0){
            return 0;
        }
        
        else{
            memset(dp,-1,sizeof(dp));
            int k = ans(s,one_count,3);
            if(one_count == 0){
                return k - 1;
            }
            
            return k;
        }
    }
};