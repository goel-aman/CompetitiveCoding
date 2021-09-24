import java.lang.Math;
import java.util.*;

abstract class Shape{  
    public int a,b,c,s,p,h;
    abstract int numberOfSides();  
    abstract int calculateArea();
}  

class Triangle extends Shape{
    int numberOfSides(){
        return 3;
    }

    int calculateArea(){
        int s = (a + b + c)/2;
        int value = s * (s - a) * (s - b) * (s - c);
        int ans =(int) Math.sqrt(value);
        return ans;
    }
}

class Square extends Shape{
    int numberOfSides(){
        return 4;
    }

    int calculateArea(){
        int ans = (a * a);
        return ans;
    }
}

class Pentagon extends Shape{
    int numberOfSides(){
        return 5;
    }

    int calculateArea(){
        int ans = ((p * a)/2);
        return ans;
    }
}

class Hexagon extends Shape{
    int numberOfSides(){
        return 6;
    }

    int calculateArea(){
        int ans = (6 * a * h)/2;
        return ans;
    }
}

class Octagon extends Shape{
    int numberOfSides(){
        return 8;
    }

    int calculateArea(){
        int ans = (8 * a * h)/2;
        return ans;
    }
} 
public class aman{
    public static void main(String[] args){
        Shape s;
        s = new Triangle();
        s.a = 4;
        s.b = 3;
        s.c = 5;
        s.h = 4;
        s.p = 9;
        System.out.println("printing sides of triangle");
        System.out.println(s.numberOfSides());
        System.out.println("printing area of triangle");
        System.out.println(s.calculateArea());

        s = new Square();
        s.a = 4;
        s.b = 3;
        s.c = 5;
        s.h = 4;
        s.p = 9;
        System.out.println("printing sides of square");
        System.out.println(s.numberOfSides());
        System.out.println("printing area of square");
        System.out.println(s.calculateArea());

        s = new Pentagon();
        s.a = 4;
        s.b = 3;
        s.c = 5;
        s.h = 4;
        s.p = 9;
        System.out.println("printing sides of pentagon");
        System.out.println(s.numberOfSides());
        System.out.println("printing area of pentagon");
        System.out.println(s.calculateArea());

        s = new Hexagon();
        s.a = 4;
        s.b = 3;
        s.c = 5;
        s.h = 4;
        s.p = 9;
        System.out.println("printing sides of hexagon");
        System.out.println(s.numberOfSides());
        System.out.println("printing area of hexagon");
        System.out.println(s.calculateArea());


        s = new Octagon();
        s.a = 4;
        s.b = 3;
        s.c = 5;
        s.h = 4;
        s.p = 9;
        System.out.println("printing sides of octagon");
        System.out.println(s.numberOfSides());
        System.out.println("printing area of octagon");
        System.out.println(s.calculateArea());

    }
}