#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        if(length == 0 || length == 1){
            return 0;
        }
        int ** matrix = new int*[k + 1];
        for(int i=0;i<=k;i++){
            matrix[i] = new int[length];
        }
        // int matrix[k + 1][length];
        for(int i=0;i<length;i++){
            matrix[0][i] = 0;
        }
        for(int i=0;i<=k;i++){
            matrix[i][0] = 0;
        }

        for(int i=1;i<=k;i++){
            int maxx = INT_MIN;
            for(int j=1;j<length;j++){
                maxx = max(matrix[i - 1][j - 1] - prices[j - 1],maxx);
                int ans= max(maxx + prices[j],matrix[i][j-1]);
                matrix[i][j] = ans;
            }
        }
        return matrix[k][length - 1];
    }
};