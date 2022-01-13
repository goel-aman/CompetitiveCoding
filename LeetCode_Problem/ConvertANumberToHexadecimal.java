import java.io.*;
import java.util.*;


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