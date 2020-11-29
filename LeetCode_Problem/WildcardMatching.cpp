class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.length() + 1][s.length() + 1];
        int plength = p.length();
        int slength = s.length();
        for(int i=p.length();i>=0;i--){
            for(int j=s.length();j>=0;j--){
                if(i == p.length() && j == s.length() ){
                    dp[i][j] = true;
                }
                else if(i == p.length()){
                    dp[i][j] = false;
                }
                else if(j == s.length()){
                    if(p[i] == '*'){
                        dp[i][j] = dp[i+1][j];
                    }else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(p[i] == '?'){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else if(p[i] == '*'){
                        dp[i][j] = (dp[i+1][j] || dp[i][j +1]);
                    }
                    else if(p[i] == s[j]){
                        dp[i][j] = dp[i + 1][j+1];
                    }else{
                        dp[i][j] = false;
                    }
                        
                }
                
            }
        }
        return dp[0][0];
    }
};