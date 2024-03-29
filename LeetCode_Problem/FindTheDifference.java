import java.io.*;
import java.util.*;

// 389. Find the Difference
// You are given two strings s and t.
// String t is generated by random shuffling string s
//  and then add one more letter at a random position.
// Return the letter that was added to t.

// Example 1:
// Input: s = "abcd", t = "abcde"
// Output: "e"
// Explanation: 'e' is the letter that was added.

// Example 2:
// Input: s = "", t = "y"
// Output: "y"
 
// Constraints:
// 0 <= s.length <= 1000
// t.length == s.length + 1
// s and t consist of lowercase English letters.

class Solution {
    public char findTheDifference(String s, String t) {
        int arr[] = new int[26];
        for(int i=0;i<t.length();i++){
            int position = (int) (t.charAt(i) - 'a');
            arr[position]++;
        }

        for(int i=0;i<s.length();i++){
            int position = (int) (s.charAt(i) - 'a');
            arr[position]--;
        }

        int index = -1;
        for(int i=0;i<26;i++){
            if(arr[i] != 0){
                index = i;
                break;
            }
        }
        char ans =(char)('a' + index);
        return ans;
    }
}