#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i=0;i<mat.size();i++){
            sum  += mat[i][i];
            sum += mat[i][n - 1 - i];
        }
        if(n%2 != 0){
            int m = n/2;
            sum -= mat[m][m];
        }

        return sum;
    }
};