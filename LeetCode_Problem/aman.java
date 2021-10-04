import java.lang.Math;
import java.util.*;

  

class Performance {
    public int yearsOfExperience;
    public ArrayList<Integer> rating = new ArrayList<Integer>();
} 
public class aman{
    public static void main(String[] args){
        System.out.println("Please Enter The Total Number Of Employees");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Performance[] arr;
        arr = new Performance[n];

        for(int i=0;i<n;i++){
            arr[i] = new Performance();
            System.out.println("Enter Year Of Experience");
            int yearOfExperience = sc.nextInt();
            arr[i].yearsOfExperience = yearOfExperience;
            for(int j=0;j<yearOfExperience;j++){
                System.out.println("Enter rating: ");
                int rating = sc.nextInt();
                arr[i].rating.add(rating);
            }                      
        }

        // calculating average
        int totalRating = 0,totalYearOfExperience = 0;

        for(int i=0;i<n;i++){
            totalYearOfExperience += arr[i].yearsOfExperience;

            for(int j=0;j<arr[i].yearsOfExperience;j++){
                totalRating += arr[i].rating.get(j);
            }
        }
        int averagePerformance = (totalRating / totalYearOfExperience);
        System.out.println("Therefore Average Performance Index is : " + averagePerformance);
    }
}