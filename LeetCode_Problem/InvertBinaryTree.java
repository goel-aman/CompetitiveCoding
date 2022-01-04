import java.util.*;
import java.io.*;

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

public class InvertBinaryTree {
    public static void main(String args[]){

    } 

    public TreeNode invertTree(TreeNode root) {
        if(root == null){
            return root;
        }
        
        TreeNode leftNode = root.left;
        TreeNode rightNode = root.right;
        
        root.left = invertTree(rightNode);
        root.right = invertTree(leftNode);
        
        return root;
    }
}
