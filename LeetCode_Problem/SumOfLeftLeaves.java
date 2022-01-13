import java.io.*;
import java.util.*;

// 404. Sum of Left Leaves
// Given the root of a binary tree, return the sum of all left leaves.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with 
// values 9 and 15 respectively.

// Example 2:
// Input: root = [1]
// Output: 0

// Constraints:
// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000

public class SumOfLeftLeaves {
    
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


class Solution {
    
    public int sumOfLeftLeavesHelper(TreeNode root,boolean cameLeft){
        if(root.left == null && root.right == null){
            if(cameLeft == true){
                return root.left.val;
            }
            return 0;
        }
        
        int value = 0;
        if(root.right != null){
            value += sumOfLeftLeavesHelper(root.right,false);
        }

        if(root.left != null){
            value += sumOfLeftLeavesHelper(root.left,true);
        }
        return value;
    }
    
    public int sumOfLeftLeaves(TreeNode root) {
        int compute = sumOfLeftLeavesHelper(root,false);
        return compute;
    }
}