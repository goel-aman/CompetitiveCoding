import java.util.*;
import java.io.*;

public class a {
    public static void main(String[] args){
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t > 0){
            t--;
            int n,l;
            n = sc.nextInt();
            l = sc.nextInt();

            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }

            int ans = 0;
            for(int i=0;i<l;i++){
                int zero = 0;
                int one = 0;
                for(int j=0;j<n;j++){
                    int val = (1<<i);
                    if((val&arr[j]) > 0){
                        one++;
                    }else{
                        zero++;
                    }
                }
                if(one >= zero){
                    ans += (1<<i);
                }else{
                    ans += 0;
                }
            }
            System.out.println(ans);
        }
    }
}
