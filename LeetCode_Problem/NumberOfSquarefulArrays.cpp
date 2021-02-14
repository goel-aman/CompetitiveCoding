// 996. Number of Squareful Arrays

// Given an array A of non-negative integers, the array is squareful if for every pair
//  of adjacent elements, their sum is a perfect square.

// Return the number of permutations of A that are squareful.  Two permutations A1 and
//  A2 differ if and only if there is some index i such that A1[i] != A2[i].

 
// Example 1:
// Input: [1,17,8]
// Output: 2
// Explanation: 
// [1,8,17] and [17,8,1] are the valid permutations.

// Example 2:
// Input: [2,2,2]
// Output: 1
 
// Note:
// 1 <= A.length <= 12
// 0 <= A[i] <= 1e9

#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,unordered_set<int>> um;
    unordered_map<int,int> count;
    int res = 0;
public:
    void dfs(int element,int arrayLength){
        count[element]--;
        if(arrayLength == 0){
            res++;
        }

        for(auto var : um[element]){
            if(count[var] > 0){
                int val = sqrt(element + var);
                if(element + var == val * val){
                    dfs(var,arrayLength - 1);
                }
            }
        }
        count[element]++;
    }

    int numSquarefulPerms(vector<int>& A) {
        for(auto var : A){
            count[var]++;
        }

        for(auto i : count){
            for(auto j : count){
                int squareroot = sqrt(i.first + j.first);
                if(i.first + j.first == squareroot * squareroot){
                    um[i.first].insert(j.first);
                }
            }
        }
        int arrayLength = A.size();
        for(auto element : count){
            dfs(element.first,arrayLength - 1);
        }
        return res;
    }
};