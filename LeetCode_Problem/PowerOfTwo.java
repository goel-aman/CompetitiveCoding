import java.util.*;
import java.io.*;


public class PowerOfTwo {
    public static void main(String args[]){

    }  
    
    
    public boolean isPowerOfTwo(int n) {
        int countSet = 0;
        while(n > 0){
            int lastBit = (n&1);
            if(lastBit == 1){
                countSet++;
            }

            n = (n>>1);
            if(countSet > 1){
                return false;
            }
        }
        if(countSet > 1 || countSet == 0){
            return false;
        }
        return true;
    }
}
