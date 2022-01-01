import java.util.*;

// Remove Linked List Elements
// Given the head of a linked list and an integer val, 
// remove all the nodes of the linked list that has 
// Node.val == val, and return the new head.

// Example 1:
// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// Example 2:
// Input: head = [], val = 1
// Output: []

// Example 3:
// Input: head = [7,7,7,7], val = 7
// Output: []
 
// Constraints:
// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50

public class RemoveLinkedListElements {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
   public static void main(String[] args){

   } 

   public ListNode removeElements(ListNode head, int val) {
        ListNode temp = head;
        while(temp != null){
            if(temp.val == val){
                temp = temp.next;
                continue;
            }
            break;
        }

        if(temp == null){
            return null;
        }

        // ListNode ans = temp;
        ListNode prev = temp;
        ListNode current = temp.next;

        while(current != null){
            while(current != null && current.val == val){
                current = current.next;
            }

            prev.next = current;
            prev = current;
            if(prev != null){
                current = prev.next;
            }
        }
        return temp;
    }
}
