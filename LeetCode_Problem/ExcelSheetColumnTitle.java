import java.io.*;
import java.util.*;

public class ExcelSheetColumnTitle {
    public static void main(String[] args){

    }

    public String convertToTitle(int columnNumber) {
        String ans = "";
        int value = columnNumber;
        while(value > 0){
            value--;
            int nextNumber = value / 26;
            char element = (char) ('A' + value%26);
            ans = element + ans;
            value = nextNumber;
        }
        
        
        return ans;
    }
}
