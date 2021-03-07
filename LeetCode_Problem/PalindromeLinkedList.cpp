// 234. Palindrome Linked List

// Given the head of a singly linked list, 
// return true if it is a palindrome.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
// Follow up: Could you do it in O(n) time and O(1) space?

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        stack<int> st;
        vector<int> s;
        while(temp != NULL){
            st.push(temp->val);
            s.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=0;i<s.size();i++){
            if(s[i] == st.top()){
                st.pop();
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};