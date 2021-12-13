import java.util.*;

import LeetCode_Problem.intersectionOfTwoLinkedList;

class MyException extends Exception
{
    public MyException(String s)
    {
        // Call constructor of parent Exception
        super(s);
    }
}
  

public class exam {
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        try{
            int value =  a - b;
            if(value > 0){
                throw new MyException("POSITIVE");
            }

            if(value == 0){
                throw new MyException("NEUTRAL");
            }

            if(value < 0){
                throw new MyException("NEGATIVE");
            }
        }catch(MyException ex)
        {
            System.out.println(ex.getMessage());
        }
    }
}
