// 547. Number of Provinces

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b,
//  and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly 
// connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

#include<bits/stdc++.h>
using namespace std;
class dsu{
    private:
    int * parent;

    public:

    dsu(int n){
        parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }
    
    void unions(int x,int y){
        int xParent = findParent(x);
        int yParent = findParent(y);
        if(xParent != yParent){
            parent[xParent] = yParent;
        }
        return;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        dsu a(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                    if(isConnected[i][j] == 1){
                        a.unions(i,j);
                    }    
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i == a.findParent(i)){
                ans++;
            }
        }
        return ans;
    }
};