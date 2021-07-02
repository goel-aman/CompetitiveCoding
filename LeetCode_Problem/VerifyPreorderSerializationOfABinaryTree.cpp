#include<bits/stdc++.h>
using namespace std;

// 331. Verify Preorder Serialization of a Binary Tree

// One way to serialize a binary tree is to use preorder traversal. 
// When we encounter a non-null node, we record the node's value. 
// If it is a null node, we record using a sentinel value such
//  as '#'.
 
// For example, the above binary tree can be serialized to the
//  string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a
//  null node.

// Given a string of comma-separated values preorder, return true
//  if it is a correct preorder traversal serialization of a binary
//  tree.

// It is guaranteed that each comma-separated value in the string
//  must be either an integer or a character '#' representing 
// null pointer.

// You may assume that the input format is always valid.

// For example, it could never contain two consecutive commas,
//  such as "1,,3".
// Note: You are not allowed to reconstruct the tree.

// Example 1:
// Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true

// Example 2:
// Input: preorder = "1,#"
// Output: false

// Example 3:
// Input: preorder = "9,#,#,1"
// Output: false
 
// Constraints:
// 1 <= preorder.length <= 104
// preoder consist of integers in the range
//  [0, 100] and '#' separated by commas ','.


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int preorderLength = preorder.length();
        if(preorderLength == 0){
            return true;
        }

        if(preorder[0] == '#'){
            if(preorderLength == 1){
                return true;
            }else{
                return false;
            }
        }
        string line = preorder;
        stringstream check1(line);
        vector<string> tokens;
        string intermediate;
        while(getline(check1,intermediate,',')){
            tokens.push_back(intermediate);
        }
        int tokensLength = tokens.size();
        int n = 2;

        for(int i=1;i<tokensLength;i++){
            if(tokens[i] != "#"){
                n = n - 1;
                if(n < 0){
                    return false;
                }

                n += 2;

                if(n < 0){
                    return false;
                }
                continue;
            }

            if(tokens[i] == "#"){
                n = n - 1;
                if(n < 0){
                    return false;
                }
            }
        }


        if(n != 0){
            return false;
        }
        return true;
    }
};