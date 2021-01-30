// Vertical Order Traversal of a Binary Tree

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (x, y), its left and right children will be at positions
//  (x - 1, y - 1) and (x + 1, y - 1) respectively.

// The vertical order traversal of a binary tree is a list of non-empty reports for each 
// unique x-coordinate from left to right. Each report is a list of all nodes at a given
//  x-coordinate. The report should be primarily sorted by y-coordinate from highest 
// y-coordinate to lowest. If any two nodes have the same y-coordinate in the report, 
// the node with the smaller value should appear earlier.

// Return the vertical order traversal of the binary tree.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation: Without loss of generality, we can assume the root node is at position (0, 0):
// The node with value 9 occurs at position (-1, -1).
// The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2).
// The node with value 20 occurs at position (1, -1).
// The node with value 7 occurs at position (2, -2).
// Example 2:


// Input: root = [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation: The node with value 5 and the node with value 6 have the same position according to the given scheme.
// However, in the report [1,5,6], the node with value 5 comes first since 5 is smaller than 6.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 1000




#include<bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class elem{
    public:
    int valu;
    int y_cor;
};

class Solution {
    unordered_map<int,vector<elem>> um;
    int maxx = INT_MIN;
    int minn = INT_MAX;
public:
    void verticalTraversal(TreeNode* root,int value,int ycoor){
        if(root == NULL){
            return;
        }
        
        maxx = max(value , maxx); 
        minn = min(value,minn);
        elem a;
        a.valu = root->val;
        a.y_cor = ycoor;
        um[value].push_back(a);

        if(root->left != NULL){
            verticalTraversal(root->left,value - 1,ycoor - 1);
        }

        if(root->right != NULL){
            verticalTraversal(root->right,value + 1,ycoor - 1);
        }

        return;
    }

    bool compare(elem a,elem b){
        if(a.y_cor > b.y_cor){
            return true;
        }

        if(a.y_cor == b.y_cor){
            if(a.valu < b.valu){
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL){
            vector<vector<int>> v;
            return v;
        }

        vector<vector<int>> ans;
        for(int i=minn;i<=maxx;i++){
            vector<elem> vv = um[i];
            sort(vv.begin(),vv.end(),compare);
        }
    }
};
