#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& books, int shelf_width,int i,int w,int h){
        if(i>=books.size()){
            return h;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int ans=h+solve(books,shelf_width,i+1,books[i][0],books[i][1]);
        if(w+books[i][0]<=shelf_width){
            ans=min(ans,solve(books,shelf_width,i+1,w+books[i][0],max(h,books[i][1])));
        }
        return dp[i][w]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        memset(dp,-1,sizeof(dp));
        return solve(books,shelf_width,0,0,0);
    }
};