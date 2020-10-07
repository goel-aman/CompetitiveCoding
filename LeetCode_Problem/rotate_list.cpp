/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0){
            return head;
        }
        
        if(head == NULL){
            return NULL;
        }
        
        if(head->next == NULL){
            return head;
        }
        
        int length = 1;
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            length++;
        }
        // cout<<"length is : "<<length<<endl;
        temp->next = head;
        k = k % length;
        temp = head;
        for(int i=0;i<length-k-1;i++){
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        return ans;
    }
};