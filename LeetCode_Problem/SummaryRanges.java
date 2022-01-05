import java.util.*;
import java.io.*;

public class SummaryRanges {
    public static void main(String args[]){

    }
    
    public List<String> summaryRanges(int[] nums) {
        List<String> ret = new ArrayList<String>();
        int numsLength = nums.length;
    
        if(numsLength == 0){
            return ret;
        }
    
        int min = nums[0],max = nums[0];
        for(int i=1;i<numsLength;i++){
            if(nums[i] == nums[i - 1] + 1){
                max = nums[i];
                continue;
            }
            else{
                String value = "";
                value += Integer.toString(min);
                if(max != min){
                    value += "->";
                    value += Integer.toString(max);
                }
                ret.add(value);
                min = nums[i];
                max = nums[i];
            }
        }

        String value = "";
        value += Integer.toString(min);
        if(max != min){
            value += "->";
            value += Integer.toString(max);
        }
        ret.add(value);
        return ret;
    }
}
