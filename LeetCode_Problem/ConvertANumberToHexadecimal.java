import java.io.*;
import java.util.*;


// Convert a Number to Hexadecimal
// Given an integer num, return a string representing its
//  hexadecimal representation. For negative integers, 
// two’s complement method is used.
// All the letters in the answer string should be lowercase 
// characters, and there should not be any leading zeros in 
// the answer except for the zero itself.
// Note: You are not allowed to use any built-in library
//  method to directly solve this problem.

// Example 1:
// Input: num = 26
// Output: "1a"

// Example 2:
// Input: num = -1
// Output: "ffffffff"

// Constraints:
// -231 <= num <= 231 - 1

public class ConvertANumberToHexadecimal {

}

class Solution {
    public String toHex(int num) {
        String ans = "";
        char map[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        int count = 0;
        while(num !=  0 && count < 8){
            ans = map[15 & num] + ans;
            num = (num >>>4);
            count++;
        }
        return ans;
    }
}