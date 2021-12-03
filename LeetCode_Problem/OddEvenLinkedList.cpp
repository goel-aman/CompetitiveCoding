#include<bits/stdc++.h>
using namespace std;

// 328. Odd Even Linked List
// /**
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }        

        ListNode* firstStart,*secondStart;

        ListNode* first,*second;
        first = firstStart = head;
        second = head->next;
        secondStart = head->next;

        while(second->next != NULL){
            if(second->next != NULL){
                first->next = second->next;
                first = first->next;
            }
            
            if(second->next->next != NULL){
                second->next = second->next->next;
                second = second->next;
            }
            
            if(first->next == NULL){
                second->next = NULL;
                break;
            }
        }

        first->next = secondStart;
        return firstStart;
    }
};