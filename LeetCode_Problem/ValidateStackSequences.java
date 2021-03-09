// 946. Validate Stack Sequences

// Given two sequences pushed and popped with distinct values, return true if and only if 
// this could have been the result of a sequence of push and pop operations on an initially empty stack.

// Example 1:
// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
// Explanation: We might do the following sequence:
// push(1), push(2), push(3), push(4), pop() -> 4,
// push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

// Example 2:
// Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// Output: false
// Explanation: 1 cannot be popped before 2.
 
// Constraints:
// 0 <= pushed.length == popped.length <= 1000
// 0 <= pushed[i], popped[i] < 1000
// pushed is a permutation of popped.
// pushed and popped have distinct values.
import java.util.*;
import java.io.*;
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        HashMap<Integer,Boolean> hm = new HashMap<Integer,Boolean>();
        Stack<Integer> st = new Stack<Integer>();
        int currPos = 0;
        for(int i=0;i<popped.length;i++){
            int val = popped[i];
            if(hm.containsKey(val)){
                if(st.peek() == val){
                    st.pop();
                    continue;
                }else{
                    return false;
                }
            }
            else{
                for(int j = currPos;j<pushed.length;j++,currPos++){
                    if(pushed[currPos] == val){
                        hm.put(pushed[currPos],true);
                        currPos++;
                        break;
                    }else{
                        hm.put(pushed[currPos],true);
                        st.push(pushed[currPos]);
                        continue;
                    }
                }
            }
        }
        return true;
    }
}
