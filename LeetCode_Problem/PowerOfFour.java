import java.util.*;
import java.io.*;

// 342. Power of Four
// Given an integer n, return true if it is a power of four. 
// Otherwise, return false.
// An integer n is a power of four, if there exists an integer
//  x such that n == 4x.

// Example 1:
// Input: n = 16
// Output: true

// Example 2:
// Input: n = 5
// Output: false

// Example 3:
// Input: n = 1
// Output: true

// Constraints:
// -231 <= n <= 231 - 1
 
// Follow up: Could you solve it without 
// loops/recursion?


public class PowerOfFour {
    public static void main(String args[]){

    }    

    public boolean isPowerOfFour(int n) {
        double value = Math.log(n)/Math.log(4);
        int value2 =(int) (Math.log(n) / Math.log(4));
        if(value == value2){
            return true;
        }
        return false;
    }
}
