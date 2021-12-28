import java.util.*;
import java.io.*;

class MiddleOfTheLinkedList {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    
    public static void main(String[] args){

    }

    public ListNode middleNode(ListNode head) {
        ListNode slowPointer = head;
        if(slowPointer == null){
            return slowPointer;
        }

        ListNode fastPointer = head;

        while(fastPointer != null && fastPointer.next != null){
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next.next;
        }

        return slowPointer;
    }
}