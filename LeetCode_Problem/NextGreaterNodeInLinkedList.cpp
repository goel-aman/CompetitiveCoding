#include<bits/stdc++.h>
using namespace std;

// 1019. Next Greater Node In Linked List
// You are given the head of a linked list with n nodes.
// For each node in the list, find the value of the next
//  greater node. That is, for each node, find the value
//  of the first node that is next to it and has a strictly
//  larger value than it.

// Return an integer array answer where answer[i] is the 
// value of the next greater node of the ith node (1-indexed).
//  If the ith node does not have a next greater node, 
// set answer[i] = 0.

// Example 1:
// Input: head = [2,1,5]
// Output: [5,5,0]

// Example 2:
// Input: head = [2,7,4,3,5]
// Output: [7,0,5,5,0]
 
// Constraints:
// The number of nodes in the list is n.
// 1 <= n <= 104
// 1 <= Node.val <= 109

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* tempHead = head;
        while(tempHead != NULL){
            ans.push_back(tempHead->val);
            tempHead = tempHead->next;
        }
        int ansLength = ans.size();
        vector<int> ret(ansLength,0);

        stack<int> st;
        st.push(ans[ansLength - 1]);
        for(int i=ansLength - 2;i>=0;i--){
            while(!st.empty() && st.top() <= ans[i]){
                st.pop();
            }

            if(st.empty()){
                ret[i] = 0;
            }else{
                ret[i] = st.top();
            }

            st.push(ans[i]);
        }

        return ret;
    }
};