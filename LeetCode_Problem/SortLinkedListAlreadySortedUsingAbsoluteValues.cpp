#include<bits/stdc++.h>
using namespace std;

// Sort Linked List Already Sorted Using Absolute Values

// Given the head of a singly linked list that is sorted in non-decreasing 
// order using the absolute values of its nodes, return the list sorted in
//  non-decreasing order using the actual values of its nodes.
 
// Example 1:
// Input: head = [0,2,-5,5,10,-10]
// Output: [-10,-5,0,2,5,10]
// Explanation:
// The list sorted in non-descending order using the absolute values of the 
// nodes is [0,2,-5,5,10,-10].
// The list sorted in non-descending order using the actual values is
//  [-10,-5,0,2,5,10].

// Example 2:
// Input: head = [0,1,2]
// Output: [0,1,2]
// Explanation:
// The linked list is already sorted in non-decreasing order.

// Example 3:
// Input: head = [1]
// Output: [1]
// Explanation:
// The linked list is already sorted in non-decreasing order.
 
// Constraints:
// The number of nodes in the list is the range [1, 105].
// -5000 <= Node.val <= 5000
// head is sorted in non-decreasing order using the absolute value of its nodes.

// Follow up:
// Can you think of a solution with O(n) time complexity?

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        vector<ListNode*> negativeValues;
        vector<ListNode*> positiveValues;

        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val >= 0){
                positiveValues.push_back(temp);                
            }else{
                negativeValues.push_back(temp);
            }
            
            temp = temp->next;
        }
        
        int negativeLength = negativeValues.size();
        int positiveLength = positiveValues.size();
        
        for(int i=1;i<positiveLength;i++){
            positiveValues[i - 1]->next = positiveValues[i]; 
        }
        if(positiveLength >= 1){
            positiveValues[positiveLength - 1]->next = NULL;
        }
        
        if(negativeLength == 0 && positiveLength > 0){
            return positiveValues[0];
        }
        
        for(int i=negativeLength - 2;i>=0;i--){
            negativeValues[i + 1] -> next = negativeValues[i];
        }
        
        if(positiveLength == 0 && negativeLength > 0){
            negativeValues[0] -> next = NULL;
            return negativeValues[negativeLength - 1];
        }
        
        if(negativeLength > 0 && positiveLength > 0){
            negativeValues[0] -> next = positiveValues[0];
            return negativeValues[negativeLength - 1];
        }
        return NULL;
    }
};