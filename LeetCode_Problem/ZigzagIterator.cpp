#include<bits/stdc++.h>
using namespace std;

// 281. Zigzag Iterator
// Given two vectors of integers v1 and v2, implement an 
// iterator to return their elements alternately.

// Implement the ZigzagIterator class:

// ZigzagIterator(List<int> v1, List<int> v2) initializes the
//  object with the two vectors v1 and v2.
// boolean hasNext() returns true if the iterator still has 
// elements, and false otherwise.
// int next() returns the current element of the iterator and 
// moves the iterator to the next element.
 
// Example 1:
// Input: v1 = [1,2], v2 = [3,4,5,6]
// Output: [1,3,2,4,5,6]
// Explanation: By calling next repeatedly until hasNext returns
//  false, the order of elements returned by next should
//  be: [1,3,2,4,5,6].

// Example 2:
// Input: v1 = [1], v2 = []
// Output: [1]

// Example 3:
// Input: v1 = [], v2 = [1]
// Output: [1]
 
// Constraints:
// 0 <= v1.length, v2.length <= 1000
// 1 <= v1.length + v2.length <= 2000
// -231 <= v1[i], v2[i] <= 231 - 1
 

// Follow up: What if you are given k vectors? How well can your 
// code be extended to such cases?
// Clarification for the follow-up question:

// The "Zigzag" order is not clearly defined and is ambiguous for 
// k > 2 cases. If "Zigzag" does not look right to you, replace 
// "Zigzag" with "Cyclic".

// Follow-up Example:

// Input: v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
// Output: [1,4,8,2,5,9,3,6,7]

class ZigzagIterator {
    vector<int> array;
    int arrayLength;
    int currentIndex;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int firstLength = v1.size();
        int secondLength = v2.size();
        int minLength = min(firstLength,secondLength);
        
        for(int i=0;i<minLength;i++){
            array.push_back(v1[i]);
            array.push_back(v2[i]);
        }
        
        for(int i=minLength;i<firstLength;i++){
            array.push_back(v1[i]);
        }
        
        for(int i=minLength;i<secondLength;i++){
            array.push_back(v2[i]);
        }
        arrayLength = firstLength + secondLength;
        currentIndex = 0;
    }

    int next() {
        int value = array[currentIndex];
        currentIndex++;
        return value;
    }

    bool hasNext() {
        if(currentIndex < arrayLength){
            return true;
        }        
        
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */