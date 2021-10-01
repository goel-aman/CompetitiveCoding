# Python3 program to construct
# a binary tree in level order.
 
# Importing Queue for use in
# Level Order Traversal
import queue
 
# Node class for holding the Binary Tree
class node:
    def __init__(self, data = None):
        self.data = data
        self.left = None
        self.right = None
 
Q = queue.Queue()
 
# Helper function helps us in adding data 
# to the tree in Level Order
def insertValue(data, root):
    newnode = node(data)
    if Q.empty() != True:
        temp = Q.get()
    if root == None:
        root = newnode
         
    # The left child of the current Node is
    # used if it is available.
    elif temp.left == None:
        temp.left = newnode
     
    # The right child of the current Node is used
    # if it is available. Since the left child of this
    # node has already been used, the Node is popped
    # from the queue after using its right child.
    elif temp.right == None:
        temp.right = newnode
        atemp = Q.get()
     
    # Whenever a new Node is added to the tree, 
    # its address is pushed into the queue.
    # So that its children Nodes can be used later.
    Q.put(newnode)
    return root
 
# Function which calls add which is responsible
# for adding elements one by one
def createTree(a, root):
    for i in range(len(a)):
        root = insertValue(a[i], root)
    return root
 
# Function for printing level order traversal
def levelOrder(root):
    Q = queue.Queue()
    Q.put(root)
    while Q.empty() != True:
        temp = Q.get()
        print(temp.data, end = ' ')
        if temp.left != None:
            Q.put(temp.left)
        if temp.right != None:
            Q.put(temp.right)
 
# Driver Code
a = [ 10, 20, 30, 40, 50, 60 ]
root = None
root = createTree(a, root)
 
levelOrder(root)
