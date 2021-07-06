#include<bits/stdc++.h>
using namespace std;

// 427. Construct Quad Tree
// Given a n * n matrix grid of 0's and 1's only.
//  We want to represent the grid with a Quad-Tree.

// Return the root of the Quad-Tree representing the grid.

// Notice that you can assign the value of a node to True 
// or False when isLeaf is False, and both are accepted 
// in the answer.

// A Quad-Tree is a tree data structure in which each internal
//  node has exactly four children. Besides, each node has
//  two attributes:

// val: True if the node represents a grid of 1's or False if 
// the node represents a grid of 0's. 
// isLeaf: True if the node is leaf node on the tree or False
//  if the node has the four children.

// class Node {
//     public boolean val;
//     public boolean isLeaf;
//     public Node topLeft;
//     public Node topRight;
//     public Node bottomLeft;
//     public Node bottomRight;
// }
// We can construct a Quad-Tree from a two-dimensional area
//  using the following steps:

// If the current grid has the same value (i.e all 1's or all 0's)
//  set isLeaf True and set val to the value of the grid and set the
//  four children to Null and stop.
// If the current grid has different values, set isLeaf to False and
//  set val to any value and divide the current grid into four sub-grids
//  as shown in the photo.
// Recurse for each of the children with the proper sub-grid.

// If you want to know more about the Quad-Tree, you can 
// refer to the wiki.

// Quad-Tree format:
// The output represents the serialized format of a Quad-Tree
//  using level order traversal, where null signifies a path 
// terminator where no node exists below.
// It is very similar to the serialization of the binary tree.
//  The only difference is that the node is represented as a 
// list [isLeaf, val].

// If the value of isLeaf or val is True we represent it as 1 
// in the list [isLeaf, val] and if the value of isLeaf or 
// val is False we represent it as 0.

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
// Explanation: The explanation of this example is shown below:
// Notice that 0 represnts False and 1 represents True in the 
// photo representing the Quad-Tree.

// Example 2:
// Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],
// [1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],
// [1,1,1,1,0,0,0,0]]
// Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],
// [1,1],[1,1]]
// Explanation: All values in the grid are not the same. We divide
//  the grid into four sub-grids.
// The topLeft, bottomLeft and bottomRight each has the same value.
// The topRight have different values so we divide it into 4 sub-grids
//  where each has the same value.
// Explanation is shown in the photo below:

// Example 3:
// Input: grid = [[1,1],[1,1]]
// Output: [[1,1]]

// Example 4:
// Input: grid = [[0]]
// Output: [[1,0]]

// Example 5:
// Input: grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
// Output: [[0,1],[1,1],[1,0],[1,0],[1,1]]
 
// Constraints:
// n == grid.length == grid[i].length
// n == 2^x where 0 <= x <= 6

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* solve(vector<vector<int>>& grid,int row1,int row2,int col1,int col2){
        if(row1 == row2 && col1 == col2){
            Node* temp = new Node();
            temp->val = grid[row1][col1];
            temp->isLeaf = true;
            return temp;
        }

        bool split = false;
        int one = 0, zero = 0;
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                if(grid[i][j] == 1){
                    one = 1;
                }

                if(grid[i][j] == 0){
                    zero = 1;
                }
                if(one != 0 && zero != 0){
                    split = true;
                    break;
                }
            }
        }

        if(split == false){
            Node* temp = new Node();
            temp->val = (one == 1) ? 1 : 0;
            temp->isLeaf = true;
            return temp;
        }

        Node* temp = new Node();
        temp->isLeaf = false;
        temp->topLeft = solve(grid,row1,(row2 + row1)/2,col1,(col2 + col1)/2);
        temp->topRight = solve(grid,row1,(row2 + row1)/2,((col2 + col1)/2) + 1,col2);
        temp->bottomLeft = solve(grid,(row2 + row1)/2 + 1,row2,col1,(col2 + col1)/2);
        temp->bottomRight = solve(grid,(row2 + row1)/2 + 1,row2,((col1 + col2)/2) + 1,col2);
        return temp;
    }

    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,grid.size() - 1,0,grid[0].size() - 1);   
    }
};