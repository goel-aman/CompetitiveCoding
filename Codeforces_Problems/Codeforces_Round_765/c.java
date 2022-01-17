import java.io.*;
import java.util.*;


public class c {
    

    public static void main(String args[]){
        int totalSign,distance,maxYouCanRemove;
        Scanner sc = new Scanner(System.in);

        totalSign = sc.nextInt();
        distance = sc.nextInt();
        maxYouCanRemove = sc.nextInt();
        int coordinates[] = new int[totalSign + 1];
        for(int i=0;i<totalSign;i++){
            coordinates[i] = sc.nextInt(); 
        }   
        coordinates[totalSign] = distance; 
        int speedLimits[] = new int[totalSign + 1];
        for(int i=0;i<totalSign;i++){
            speedLimits[i] = sc.nextInt();
        } 
        
        int dp[][] = new int[totalSign + 1][maxYouCanRemove + 1];
        for(int i=0;i<=totalSign;i++){
            for(int j=0;j<=maxYouCanRemove;j++){
                dp[i][j] = -1;
            }
        }

        System.out.println(c.minTime(0,maxYouCanRemove,coordinates,speedLimits,dp));
    }
    
    static int minTime(int index,int k,int[] coordinates,int[] speedLimits,int dp[][]){
        int length = dp.length - 1;
        if(index >= length){
            return 0;
        }

        if(dp[index][k] != -1){
            return dp[index][k];
        }

        int ans = Integer.MAX_VALUE;
        for(int remove = 0;remove <= k;remove++){
            if(index + remove >= length){
                break;
            }

            int timeTaken = (coordinates[index + remove + 1] - coordinates[index]) * speedLimits[index];
            ans = Math.min(timeTaken + minTime(index + remove + 1,k - remove,coordinates,speedLimits,dp),ans);
        }
        dp[index][k] = ans;

        return ans;
    }
}
