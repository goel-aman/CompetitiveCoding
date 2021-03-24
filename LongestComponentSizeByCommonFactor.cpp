// 952. Largest Component Size by Common Factor

// Given a non-empty array of unique positive integers A, 
// consider the following graph:

// There are A.length nodes, labelled A[0] to A[A.length - 1];
// There is an edge between A[i] and A[j] if and only if A[i] and A[j]
//  share a common factor greater than 1.
// Return the size of the largest connected component in the graph.

// Example 1:
// Input: [4,6,15,35]
// Output: 4

// Example 2:
// Input: [20,50,9,63]
// Output: 2

// Example 3:
// Input: [2,3,6,7,4,12,21,39]
// Output: 8

// Note:
// 1 <= A.length <= 20000
// 1 <= A[i] <= 100000

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans;
    unordered_map<int,int> count;
    unordered_map<int,int> um;
public:
    int findParent(int x){
        if(!um.count(x)){
            um[x] = x;
            return x;
        }

        if(um[x] == x){
            return um[x];
        }

        return um[x] = findParent(um[x]);
    }

    void merge(int x,int y){
        int xPar = findParent(x);
        int yPar = findParent(y);
        if(xPar != yPar){
            um[xPar] = yPar;
        }
        return;
    }

    int largestComponentSize(vector<int>& A) {
        int ALength = A.size();
        for(int i=0;i<ALength;i++){
            for(int j=2;j<=sqrt(A[i]);j++){
                if(A[i]%j == 0){
                    merge(A[i],j);
                    merge(A[i],A[i]/j);
                }
            }
        }
        ans = 0;
        unordered_map<int,int> umm;
        for(auto y: A){
            umm[findParent(y)]++;
            int val = umm[findParent(y)];
            ans = max(val,ans);
        }
        return ans;    
    }
};