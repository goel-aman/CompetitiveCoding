import java.util.*;
import java.io.*;

// 205. Isomorphic Strings
// Given two strings s and t, determine
//  if they are isomorphic.
// Two strings s and t are isomorphic if the
//  characters in s can be replaced to get t.

// All occurrences of a character must be 
// replaced with another character while
// preserving the order of characters. No two 
// characters may map to the same character, but 
// a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true

// Constraints:
// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

public class IsomorphicStrings{
    public static void main(String args[]){

    }

    public boolean isIsomorphic(String s, String t) {
        int sLength = s.length();
        HashMap<Character,Character> map = new HashMap<Character,Character>();

        for(int i=0;i<sLength;i++){
            char value = s.charAt(i);
            if(map.containsKey(value)){
                if(t.charAt(i) != map.get(value)){
                    return false;
                }
            }else{
                if(!map.containsValue(t.charAt(i))){
                    map.put(value,t.charAt(i));
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}

class Solution {
    
}