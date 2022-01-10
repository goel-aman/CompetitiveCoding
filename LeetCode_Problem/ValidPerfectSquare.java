import java.util.*;
import java.io.*;

// 367. Valid Perfect Square
// Given a positive integer num, write a function which
//  returns True if num is a perfect square else False.
// Follow up: Do not use any built-in library function 
// such as sqrt.

// Example 1:
// Input: num = 16
// Output: true

// Example 2:
// Input: num = 14
// Output: false

// Constraints:
// 1 <= num <= 2^31 - 1

class Solution {
    public boolean isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        int temp = num;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        Boolean enter = false;
        while(temp%2 == 0){
            enter = true;
            temp = temp/2;
            if(map.containsKey(2)){
                map.put(2,map.get(2) + 1);
            }else{
                map.put(2,1);
            }
            enter = true;
        }

        for(int i=3;i<=Math.sqrt(num);i+=2){
            while(temp%i == 0){
                enter = true;
                temp = temp / i;
                if(map.containsKey(i)){
                    map.put(i,map.get(i) + 1);
                }else{
                    map.put(i,1);
                }                
            }
        }
        
        if(temp != 1){
            return false;
        }
        
        for(Map.Entry<Integer,Integer> entry : map.entrySet()){
            if(entry.getValue()%2 == 1){
                return false;
            }
        }
        
        if(enter == false){
            return false;
        }
        return true;
    }
}