/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    
    func checkValues(_ first: TreeNode? , _ second: TreeNode?) -> Bool {
        if first == nil && second == nil {
            return true
        }
        
        if(first == nil){
            return false
        }
        
        if(second == nil){
            return false
        }
        
        if(first?.val != second?.val){
            return false
        }
        
        return (checkValues(first?.left,second?.right) && checkValues(first?.right,second?.left))
    }
    
    
    func isSymmetric(_ root: TreeNode?) -> Bool {
        if root == nil {
            return true
        }
        
        return checkValues(root?.left,root?.right)
    }
}