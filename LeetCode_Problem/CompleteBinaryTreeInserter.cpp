#include<bits/stdc++.h>
using namespace std;

// 919. Complete Binary Tree Inserter
// A complete binary tree is a binary tree in which every level,
//  except possibly the last, is completely filled, and all nodes
//  are as far left as possible.

// Write a data structure CBTInserter that is initialized with a 
// complete binary tree and supports the following operations:

// CBTInserter(TreeNode root) initializes the data structure on a 
// given tree with head node root;
// CBTInserter.insert(int v) will insert a TreeNode into the tree
//  with value node.val = v so that the tree remains complete, and
//  returns the value of the parent of the inserted TreeNode;
// CBTInserter.get_root() will return the head node of the tree.
 
// Example 1:
// Input: inputs = ["CBTInserter","insert","get_root"],
//  inputs = [[[1]],[2],[]]
// Output: [null,1,[1,2]]

// Example 2:
// Input: inputs = ["CBTInserter","insert","insert","get_root"],
//  inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
// Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 
// Note:
// The initial given tree is complete and contains between 1 and 1000 nodes.
// CBTInserter.insert is called at most 10000 times per test case.
// Every value of a given or inserted node is between 0 and 5000.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class CBTInserter {
    TreeNode* head;
    queue<TreeNode*> que;
public:
    CBTInserter(TreeNode* root) {
        head = root;
        que.push(head);

        while(!que.empty()){
            TreeNode* front = que.front();
            if(front->left == NULL || front->right == NULL){
                if(front->left != NULL){
                    que.push(front->left);
                }
                break;
            }
            que.pop();

            if(front->left != NULL){
                que.push(front->left);
            }
            
            if(front->right != NULL){
                que.push(front->right);
            }
        }

    }
    
    int insert(int v) {
        TreeNode* newNode = new TreeNode(v);

        TreeNode* parent = que.front();
        int ret;
        if(parent->left == NULL){
            parent->left = newNode;
            ret = parent->val;
            que.push(newNode);
            return ret;
        }

        if(parent->right == NULL){
            parent->right = newNode;
            ret = parent->val;
            que.push(newNode);
            que.pop();
            return ret;
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */