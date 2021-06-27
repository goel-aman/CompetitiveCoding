#include<bits/stdc++.h>
using namespace std;

// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that
//  have duplicate numbers, leaving only distinct numbers from the
//  original list. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:
// Input: head = [1,1,1,2,3]
// Output: [2,3]
 
// Constraints:
// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }      
        unordered_map<int,int> um;
        ListNode* temp = head;
        while(temp != NULL){
            um[temp->val]++;
            temp = temp->next;
        }

        ListNode* ret = NULL;
        ListNode* answer = ret;
        temp = head;
        bool first = true;
        while(temp != NULL){
            if(um[temp->val] == 1){
                if(first == true){
                    ret = new ListNode(temp->val);
                    answer = ret;
                    first = false;
                }else{
                    ret->next = new ListNode(temp->val);
                    ret = ret->next;
                }
            }
            temp = temp->next;
        }
        return answer;
    }
};