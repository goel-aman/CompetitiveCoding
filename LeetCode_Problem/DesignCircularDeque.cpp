#include<bits/stdc++.h>
using namespace std;

// 641. Design Circular Deque
// Design your implementation of the circular 
// double-ended queue (deque).

// Implement the MyCircularDeque class:
// MyCircularDeque(int k) Initializes the deque with a 
// maximum size of k.
// boolean insertFront() Adds an item at the front of 
// Deque. Returns true if the operation is successful,
//  or false otherwise.
// boolean insertLast() Adds an item at the rear of 
// Deque. Returns true if the operation is successful,
//  or false otherwise.
// boolean deleteFront() Deletes an item from the front
//  of Deque. Returns true if the operation is successful,
//  or false otherwise.
// boolean deleteLast() Deletes an item from the rear of 
// Deque. Returns true if the operation is successful, or 
// false otherwise.
// int getFront() Returns the front item from the Deque.
//  Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns
//  -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty,
//  or false otherwise.
// boolean isFull() Returns true if the deque is full,
// or false otherwise.
 
// Example 1
// Input
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", 
// "insertFront", "getRear", "isFull", "deleteLast", "insertFront", 
// "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// Output
// [null, true, true, true, false, 2, true, true, true, 4]

// Explanation
// MyCircularDeque myCircularDeque = new MyCircularDeque(3);
// myCircularDeque.insertLast(1);  // return True
// myCircularDeque.insertLast(2);  // return True
// myCircularDeque.insertFront(3); // return True
// myCircularDeque.insertFront(4); // return False,
//  the queue is full.
// myCircularDeque.getRear();      // return 2
// myCircularDeque.isFull();       // return True
// myCircularDeque.deleteLast();   // return True
// myCircularDeque.insertFront(4); // return True
// myCircularDeque.getFront();     // return 4
 
// Constraints:
// 1 <= k <= 1000
// 0 <= value <= 1000
// At most 2000 calls will be made to insertFront, insertLast, 
// deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.



class MyCircularDeque {
    vector<int> deque;
    int start;
    int length;
    int end;
    int size;
    public:
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        deque.resize(k);
        size = k;
        length = 0;
        start = 0;
        end = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(length == size){
            return false;
        }        

        deque[(start - 1 + size)%size] = value;
        start = (start - 1 + size)%size;
        length++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(length == size){
            return false;
        }

        deque[end] = value;
        end = (end + 1)%size;
        length++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(length == 0){
            return false;
        }
        
        start = (start + 1)%size;
        length--;
        return true;    
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(length == 0){
            return false;
        }

        end = (end - 1 + size)%size;
        length--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(length == 0){
            return -1;
        }

        return deque[start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(length == 0){
            return -1;
        }

        return deque[(end - 1 + size)%size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(length == 0){
            return true;
        }        

        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(length == size){
            return true;
        }

        return false;
    }
};
