import java.util.*;
import java.io.*;

// 409. Longest Palindrome
// Given a string s which consists of lowercase or uppercase
// letters, return the length of the longest palindrome that 
// can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered
//  a palindrome here.

// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose
//  length is 7.

// Example 2:
// Input: s = "a"
// Output: 1

// Example 3:
// Input: s = "bb"
// Output: 2
 
// Constraints:
// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters
//  only.

public class LongestPalindrome {
    
}


class Solution {
    public int longestPalindrome(String s) {
        int sLength = s.length();
        Map<Character,Integer> map = new HashMap<Character,Integer>();
        for(int i=0;i<sLength;i++){
            if(map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),map.get(s.charAt(i)) + 1);
            }else{
                map.put(s.charAt(i),1);
            }
        }       

        int largestOdd = 0, ans = 0;
        for(Map.Entry<Character,Integer> entry : map.entrySet()){
                ans += ((entry.getValue()/2)*2);
        }
        
        return (ans == sLength) ? ans : ans + 1;
    }
}