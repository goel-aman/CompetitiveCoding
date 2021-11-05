#include<bits/stdc++.h>
using namespace std;

int dp[1001][501][501];
int arrayLength;
int solve(vector<int>& array,int index,int x,int y){
    if(index == arrayLength){
        return 0;
    }

    if(array[index] > x && array[index] > y){
        return 0;
    }

    if(dp[index][x][y] != -1){
        return dp[index][x][y];
    }

    if(dp[index][y][x] != -1){
        return dp[index][y][x];
    }

    int value1 = 0 , value2 = 0;
    if(array[index] <= x){
        value1 = solve(array,index + 1,x - array[index],y) + 1;
    }

    if(array[index] <= y){
        value2 = solve(array,index + 1,x, y - array[index]) + 1;
    }
    int ans = max(value1,value2);
    dp[index][y][x] = ans;
    dp[index][x][y] = ans;
    return ans;
}

int main(){
    cin>>arrayLength;
    vector<int> array;
    
    for(int i=0;i<arrayLength;i++){
        int value;
        cin>>value;
        array.push_back(value);
    }    

    int x,y; // number of hours worker can work
    cin>>x>>y;
    sort(array.begin(),array.end());
    memset(dp,-1,sizeof(dp));   
    cout<<solve(array,0,x,y);
}