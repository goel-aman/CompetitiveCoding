#include<bits/stdc++.h>
using namespace std;

// 143. Reorder List

// You are given the head of a singly linked-list.
// The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. 
// Only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 
// Constraints:
// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return ;
        }
        ListNode* temp = head;
        vector<ListNode*> vec;
        while(temp != NULL){
            vec.push_back(temp);
            temp = temp->next;
        }
        ListNode* prev = NULL;
        int vecLength = vec.size();
        int start = 0;
        int end = vecLength -1;
        while(start <= end){
            if(start == 0){
                // cout<<"hello it worked"<<endl;
                prev = vec[start];
                cout<<prev->val<<endl;
                prev->next = vec[end];
                prev = prev->next;
                cout<<prev->val<<endl;
                start++;
                end--;
                // cout<<"it got completed"<<endl;
                continue;
            }

            if(start == end){
                prev->next = vec[start];
                start++;
                prev = prev->next;
                prev->next = NULL;
                continue;
            }
                
            prev->next = vec[start];
            prev = prev->next;
            // cout<<prev->val<<endl;
            prev->next = vec[end];
            prev = prev->next;
            prev->next = NULL;
            // cout<<prev->val<<endl;
            start++;
            end--;
        }
    
        return ;
    }
};