package LeetCode_Problem;
import java.util.*;
public class intersectionOfTwoLinkedList {

}


//  * Definition for singly-linked list.
 public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }
 
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null){
            return null;
        }
        HashMap<ListNode,Boolean> hm = new HashMap<ListNode,Boolean>();
        ListNode temp = headA;
        while(temp != null){
            hm.put(temp,true);
            temp = temp.next;
        }
        
        temp = headB;
        while(temp != null){
            if(hm.containsKey(temp)){
                return temp;
            }
            
            temp = temp.next;
        }
        return null;
    }
}
