#include<bits/stdc++.h>
using namespace std;

// 576. Out of Boundary Paths

class Solution {
    unordered_map<string,int> um;
    int mod = 1e9 + 7;
public:
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow >= m || startColumn >= n || startRow < 0 || startColumn < 0){
            return 1;
        }

        if(maxMove <= 0){
            return 0;
        }

        string s = to_string(maxMove) + ";" + to_string(startRow) + ";" + to_string(startColumn);
        if(um.count(s)){
            return um[s];
        }
        int ans = 0;
        ans = (ans +  findPaths(m,n,maxMove - 1,startRow + 1,startColumn))%mod;
        ans = ( ans +  findPaths(m,n,maxMove - 1,startRow - 1,startColumn))%mod;
        ans = (ans + findPaths(m,n,maxMove - 1,startRow,startColumn + 1))%mod;
        ans = (ans + findPaths(m,n,maxMove -1 ,startRow,startColumn - 1))%mod;

        return um[s] = ans;
    }
};