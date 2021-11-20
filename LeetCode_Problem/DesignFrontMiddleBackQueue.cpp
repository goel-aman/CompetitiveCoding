#include<bits/stdc++.h>
using namespace std;

// 1670. Design Front Middle Back Queue
// Design a queue that supports push and pop operations 
// in the front, middle, and back.

// Implement the FrontMiddleBack class:
// FrontMiddleBack() Initializes the queue.
// void pushFront(int val) Adds val to the front of 
// the queue.
// void pushMiddle(int val) Adds val to the middle 
// of the queue.
// void pushBack(int val) Adds val to the back of the queue.
// int popFront() Removes the front element of the 
// queue and returns it. If the queue is empty, return -1.
// int popMiddle() Removes the middle element of the queue
//  and returns it. If the queue is empty, return -1.
// int popBack() Removes the back element of the queue and 
// returns it. If the queue is empty, return -1.
// Notice that when there are two middle position choices, 
// the operation is performed on the frontmost middle 
// position choice. For example:

// Pushing 6 into the middle of [1, 2, 3, 4, 5] results
// in [1, 2, 6, 3, 4, 5].
// Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 
// and results in [1, 2, 4, 5, 6].
 
// Example 1:
// Input:
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", 
// "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack",
//  "popFront"]
// [[], [1], [2], [3], [4], [], [], [], [], []]
// Output:
// [null, null, null, null, null, 1, 3, 4, 2, -1]

// Explanation:
// FrontMiddleBackQueue q = new FrontMiddleBackQueue();
// q.pushFront(1);   // [1]
// q.pushBack(2);    // [1, 2]
// q.pushMiddle(3);  // [1, 3, 2]
// q.pushMiddle(4);  // [1, 4, 3, 2]
// q.popFront();     // return 1 -> [4, 3, 2]
// q.popMiddle();    // return 3 -> [4, 2]
// q.popMiddle();    // return 4 -> [2]
// q.popBack();      // return 2 -> []
// q.popFront();     // return -1 -> [] (The queue is empty)
 
// Constraints:
// 1 <= val <= 109
// At most 1000 calls will be made to pushFront, pushMiddle, pushBack,
//  popFront, popMiddle, and popBack.

class FrontMiddleBackQueue {
    vector<int> arr;
    int arrLength;
public:
    FrontMiddleBackQueue() {
        arrLength = 0;
    }
    
    void pushFront(int val) {
        arr.insert(arr.begin(),val);
        arrLength++;
        return ;
    }
    
    void pushMiddle(int val) {
        int isEven = (arrLength%2 == 0) ? 1 : 0;
        int mid = arrLength / 2;
        
        
        arr.insert(arr.begin() + mid,val);
        arrLength++;
        return ;
    }
    
    void pushBack(int val) {
        arr.push_back(val);
        arrLength++;
        return ;
    }
    
    int popFront() {
        if(arrLength == 0){
            return -1;
        }
        
        int ret = arr[0];
        arr.erase(arr.begin());
        arrLength--;
        return ret;
    }
    
    int popMiddle() {
        if(arrLength == 0){
            return -1;
        }
        
        bool isEven = ((arrLength%2 == 0) ? 1: 0);
        int mid = arrLength/2;
        if(isEven){
            mid -= 1;
        }
        
        int value = arr[mid];
        arrLength--;
        arr.erase(arr.begin() + mid );
        return value;
    }
    
    int popBack() {
        if(arrLength == 0){
            return -1;
        }
        int ret = arr[arrLength - 1];
        arr.erase(arr.begin() + arrLength - 1);
        arrLength--;
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */