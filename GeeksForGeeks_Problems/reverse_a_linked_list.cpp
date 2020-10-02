/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
// Should reverse list and return new head.
Node* reverse(Node *head)
{
struct Node* prev;
struct Node * current;
struct Node * next; 

prev = NULL;
current = head;
next = NULL;
while(current != NULL){
    next = current ->next;
    current->next = prev;
    prev = current ;
    current = next;
    if(current != NULL){
        next = current->next;
    }
}
return prev;
  // Your code here
}