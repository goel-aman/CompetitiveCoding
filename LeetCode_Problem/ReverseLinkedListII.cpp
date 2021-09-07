#include<bits/stdc++.h>
using namespace std;

// 92. Reverse Linked List II
// Given the head of a singly linked list and two 
// integers left and right where left <= right, reverse
//  the nodes of the list from position left to position
//  right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]
 
// Constraints:
// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
 
// Follow up: Could you do it in one pass?

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        stack<int> st;
        for(int i=left;i<=right;i++){
            st.push(vec[i-1]);
        }

        for(int i=left;i<=right;i++){
            vec[i-1] = st.top();
            st.pop();
        }
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = vec[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};