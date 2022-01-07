import java.util.*;
import java.io.*;

class Solution {
    public int addDigits(int num) {
        int temp = num;
        int ans = 0;
        while(temp >= 10){
            ans++;
            String value = Integer.toString(temp);
            int sum = 0;
            for(int i=0;i<value.length();i++){
                int digit = (int) (value.charAt(i) - '0');
                sum += digit;
            }
            temp = sum;
        }
        
        return temp;
    }

    public static void main(String args[]){

    }
}