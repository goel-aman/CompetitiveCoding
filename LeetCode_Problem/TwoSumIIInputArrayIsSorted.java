import java.util.ArrayList;
import java.util.*;
import java.io.*;

public class TwoSumIIInputArrayIsSorted{
    public static void main(String args[]){

    }

    class Solution {
        public int[] twoSum(int[] numbers, int target) {
            int numbersLength = numbers.length;
            // System.out.println("numbersLength is : " + numbersLength);
            
            int frontIndex = 0,endIndex = numbersLength - 1;
            int arr[] = new int[2];
            // System.out.println("frontIndex is : " + frontIndex + " endingIndex is : " + endIndex);
            while(frontIndex < endIndex){
                int tempSum = numbers[frontIndex] + numbers[endIndex];
                if(tempSum > target){
                    endIndex--;
                    continue;
                }
                
                if(numbers[frontIndex] + numbers[endIndex] == target){
                    arr[0] = (frontIndex + 1);
                    arr[1] = (endIndex  + 1);
                    break;
                }
                
                if(tempSum < target){
                    frontIndex++;
                    continue;
                }
            }
            return arr;
        }
    }
}