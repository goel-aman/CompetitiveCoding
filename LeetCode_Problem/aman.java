import java.io.*;
import java.lang.Math;
import java.util.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
public class aman{
    public static void main(String[] args) throws Exception {        
        Scanner sc = new Scanner(System.in);
        int numberOfStudents = sc.nextInt();
        sc.nextLine();
        File outputFile = new File("outputFirst.txt");
        FileOutputStream fos = new FileOutputStream(outputFile,true);
        while (numberOfStudents > 0) {
            String registrationNumber = sc.nextLine();
            for(int i=0;i<registrationNumber.length();i++){
                fos.write(registrationNumber.charAt(i));
            }
            fos.write('\n');
            numberOfStudents--;
        }
        File outputFile2 = new File("output2.txt");
        FileOutputStream fos2 = new FileOutputStream(outputFile2,true);
        File inputFile = new File("outputFirst.txt");
        FileInputStream fis = new FileInputStream(inputFile);
        int content;
        String number = "";
        while ((content = fis.read()) != -1) {
            if(content == 10){
                number = number.toUpperCase();
                for(int i=0;i<number.length();i++){
                    fos2.write(number.charAt(i));
                }
                fos2.write('\n');
                number = "";
            }else{
                number = number + (char) (content);
            }
        }
    }
}