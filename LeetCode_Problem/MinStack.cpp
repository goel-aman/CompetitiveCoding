// 155. Min Stack

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 

// Constraints:

// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.

#include<bits/stdc++.h>
using namespace std;
class MinStack {
    vector<int> v;
    vector<int> mi;
    int pos;
public:
    /** initialize your data structure here. */
    MinStack(): v(30001), mi(30001) {
        v.clear();
        pos = 0;
    }
    
    void push(int x) {
        if(pos == 0){
            mi[pos] = x;
        }else{
            mi[pos] = min(x,mi[pos - 1]);
        }
        v[pos] = x;
        pos++;
    }
    
    void pop() {
        if(pos == 0){
            return ;
        }
        pos--;
    }
    
    int top() {
        return v[pos - 1];
    }
    
    int getMin() {
        return mi[pos - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */