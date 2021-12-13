// 1.Hierarchical inheritance Assume you have a class ‘Employee’ with all basic information
//  (e_id, name, sal) and a method to display its details. Using this class create new
//  classes like ‘Manager’, ‘Team Lead’,  ‘Developer’,  and  ‘Trainee’  with  their  own
//   specific  information  (necessarily, eval_pts).  For  the  yearly  appraisal  they  
// should  earn  10  evaluation  points  in  the  last financial year. Add 15% of their 
// salary to their current salary as an increment if they are eligible. Redefine the display
//  method in the new classes to display updated details. Write a Java program to test at 
// least one object in each (four) category of employees. 

import java.util.*;

class Employee{
    int eid;
    String name;
    int sal;

    public void display(){
        System.out.println("Employee id is : " + eid);
        System.out.println("Employee name is : " + name);
        System.out.println("Employee Salary is : " + sal);
    }
}

class Manager extends Employee{
    int eval_pts;

    public void display(){
        System.out.println("Employee id is : " + eid);
        System.out.println("Employee name is : " + name);
        System.out.println("Employee Salary is : " + sal);
        System.out.println("Employee eval_pts is: " + eval_pts);
    }
}


class TeamLead extends Employee{
    int eval_pts;
    public void display(){
        System.out.println("Employee id is : " + eid);
        System.out.println("Employee name is : " + name);
        System.out.println("Employee Salary is : " + sal);
        System.out.println("Employee eval_pts is: " + eval_pts);
    }
}

class Developer extends Employee{
    int eval_pts;
    public void display(){
        System.out.println("Employee id is : " + eid);
        System.out.println("Employee name is : " + name);
        System.out.println("Employee Salary is : " + sal);
        System.out.println("Employee eval_pts is: " + eval_pts);
    }
}

class Trainee extends Employee{
    int eval_pts;
    public void display(){
        System.out.println("Employee id is : " + eid);
        System.out.println("Employee name is : " + name);
        System.out.println("Employee Salary is : " + sal);
        System.out.println("Employee eval_pts is: " + eval_pts);
    }
}

public class exam2 {
    public static void main(String[] args){
        Manager first = new Manager();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Employee salary : ");
        first.sal = sc.nextInt();
        System.out.println("Enter Employee Id : ");
        first.eid = sc.nextInt();
        System.out.println("Enter Employee name : ");
        String temp = sc.nextLine();
        first.name = sc.nextLine();
        System.out.println("Enter eval_pts : ");
        first.eval_pts = sc.nextInt();
        if(first.eval_pts >= 10){
            double updatedSalary = first.sal;
            updatedSalary += ((double) (15* first.sal) / (double) 100.0);
            System.out.println("Updated Salary of Employee is : " + updatedSalary);
        }
    }
}
