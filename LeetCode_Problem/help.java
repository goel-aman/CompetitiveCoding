import java.util.List;
import java.util.Scanner;
import java.util.*;
// import java.util.*;
class student{
    
    public String name;
    public String regno;
    public int first;
    public int second;
    public int third;
    public int fourth;
    public int fifth;
    public int sixth;
}

public class help{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<student> slow = new ArrayList<student>();
        ArrayList<student> normal = new ArrayList<student>();
        ArrayList<student> fast = new ArrayList<student>();
        
        for(int i=0;i<n;i++){
            sc.nextLine();
            student x = new student();
            String name = sc.nextLine();
            x.name = name;
            
            String reg = sc.nextLine();
            x.regno = reg;
           
            int first = sc.nextInt();
            int second = sc.nextInt();
            int third = sc.nextInt();
            int fourth = sc.nextInt();
            int fifth = sc.nextInt();
            int sixth = sc.nextInt();
            x.first = first;
            x.second = second;
            x.third = third;
            x.fourth = fourth;
            x.fifth = fifth;
            x.sixth = sixth;
            int avg = (x.first + x.second + x.third + x.fourth + x.fifth + x.sixth)/6;
            if(avg < 40){
                slow.add(x);
            }    
            else if(avg > 89){
                fast.add(x);
            }else{
                normal.add(x);
            }
        }    
        
        System.out.println("Print Slow Learner Name: ");
        for(student x : slow){
            System.out.print(x.name + " ");
        }
        System.out.println();

        System.out.println("Print normal Learner Name : ");
        for(student x : normal){
            System.out.print(x.name + " ");
        }
        System.out.println();

        System.out.println("Print Fast Learner Name: ");
        for(student x : fast){
            System.out.print(x.name + " ");
        }
        System.out.println();
    }
}