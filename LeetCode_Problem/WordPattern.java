import java.util.*;
import java.io.*;

// 290. Word Pattern
// Given a pattern and a string s, find if s
//  follows the same pattern.

// Here follow means a full match, such that there 
// is a bijection between a letter in pattern and
//  a non-empty word in s.

// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

// Example 3:
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
 
// Constraints:
// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

public class WordPattern{
    public static void main(String args[]){

    }

    public boolean wordPattern(String pattern, String s) {
        Map<Character,String> map1 = new HashMap<Character,String>();
        Map<String,Character> map2 = new HashMap<String,Character>();
        String words[] = s.split("\\s");
        int patternLength = pattern.length();
        if(patternLength != words.length){
            return false;
        }
        
        for(int i=0;i<patternLength;i++){
            
            if(map1.containsKey(pattern.charAt(i))){
                String value = map1.get(pattern.charAt(i));
                
                if(!(value.equals(words[i]))){
                    return false;
                }
            }
            
            if(map2.containsKey(words[i])){
                Character value = map2.get(words[i]);
                if(!value.equals(pattern.charAt(i))){
                    return false;
                }
            }
            else{
                map2.put(words[i],pattern.charAt(i));
                map1.put(pattern.charAt(i),words[i]);
            }
        }
        return true;       
    }
}