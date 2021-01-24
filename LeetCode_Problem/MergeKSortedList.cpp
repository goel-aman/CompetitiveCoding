// Merge k Sorted Lists

// Problem Statement
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] is sorted in ascending order.
// The sum of lists[i].length won't exceed 10^4.


#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        int count = 0;
        int vectorLength = lists.size();
        ListNode * head = new ListNode();
        ListNode* temp = head;
        ListNode* prev = head;
        int minValue = INT_MAX;
        while(true){
            minValue = INT_MAX;
            for(int i=0;i<vectorLength;i++){

                if(lists[i] == NULL){
                    continue;
                }

                if(lists[i]->val < minValue){
                    minValue = lists[i]->val;
                }
            }

            if(minValue == INT_MAX){
                break;
            }

            for(int i=0;i<vectorLength;i++){
                if( lists[i] != NULL && lists[i]->val == minValue ){
                    lists[i] = lists[i]->next;
                    break;
                }
            }
            prev = temp;
            temp->val = minValue;
            count++;
            cout<<minValue<<endl;
            temp->next = new ListNode();
            temp = temp->next;
            // minValue = INT_MIN;
        }
        if(prev != NULL){
            prev->next = NULL;    
        }
        if(count == 0){
            return NULL;
        }
        return head;    
    }
};