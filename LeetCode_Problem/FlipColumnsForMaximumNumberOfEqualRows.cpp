#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> um;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            int firstValue = matrix[i][0];
            string s = "";
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == firstValue){
                    s += "1";
                }else{
                    s += "0";
                }
            }
            um[s]++;
        }
        int ans = 0;
        for(auto &var : um){
            ans = max(ans,var.second);
        }
        return ans;
    }
};