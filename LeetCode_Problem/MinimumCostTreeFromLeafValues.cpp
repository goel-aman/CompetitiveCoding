#include<bits/stdc++.h>
using namespace std;

// 1130. Minimum Cost Tree From Leaf Values
// Given an array arr of positive integers, consider 
// all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each 
// leaf in an in-order traversal of the tree.  (Recall
//  that a node is a leaf if and only if it has 0 children.)
// The value of each non-leaf node is equal to the product
//  of the largest leaf value in its left and right subtree
//  respectively.
// Among all possible binary trees considered, return the 
// smallest possible sum of the values of each non-leaf node.
//   It is guaranteed this sum fits into a 32-bit integer.

// Example 1:
// Input: arr = [6,2,4]
// Output: 32
// Explanation:
// There are two possible trees.  The first has non-leaf node
//  sum 36, and the second has non-leaf node sum 32.

//     24            24
//    /  \          /  \
//   12   4        6    8
//  /  \               / \
// 6    2             2   4
 
// Constraints:
// 2 <= arr.length <= 40
// 1 <= arr[i] <= 15
// It is guaranteed that the answer fits into a 32-bit 
// signed integer (ie. it is less than 2^31).



class Solution {
    unordered_map<string,pair<int,int>> um;
public:
    // first is maxLeafValue, second add
    pair<int,int> solve(vector<int>& arr,int start,int end){
        if(start == end){
            return {arr[start],0};
        }
        
        string input = to_string(start) + ";" + to_string(end);
        if(um.count(input) > 0){
            return um[input];
        }

        int maxLeaf = INT_MIN;
        int sum = INT_MAX;

        for(int i=start;i<end;i++){
            pair<int,int> left = solve(arr,start,i);
            pair<int,int> right = solve(arr,i + 1,end);
            maxLeaf = max(maxLeaf,max(left.first,right.first));
            sum = min(sum,left.second + right.second + left.first * right.first);
        }
        
        um[input] = {maxLeaf,sum};
        return {maxLeaf,sum};
    }

    int mctFromLeafValues(vector<int>& arr) {
        int arrLength = arr.size();
        pair<int,int> ans = solve(arr,0,arrLength - 1);
        return ans.second;      
    }
};