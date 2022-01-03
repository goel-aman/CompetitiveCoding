import java.util.*;
import java.io.*;

class element implements Comparable<element>{
    public int value;
    public int index;

    public int compareTo(element elem){
        if(this.value > elem.value){
            return -1;
        }
        if(this.value == elem.value){
            if(this.index <= elem.index){
                return 1;
            }else{
                return -1;
            }
        }
        return 1;
    }
}


public class ContainsDuplicateII {   
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        ArrayList<element> arr = new ArrayList<element>();
        int numsLength = nums.length;
        for(int i=0;i<numsLength;i++){
            element elem = new element();
            elem.value = nums[i];
            elem.index = i;
            arr.add(elem);
        }

        Collections.sort(arr);
        for(int i=0;i<numsLength - 1;i++){
            element first = arr.get(i);
            element second = arr.get(i + 1);
            if(first.value == second.value){
                if(Math.abs(first.index - second.index) <= k){
                    return true;
                }
            }
        }
        return false;
    }
}
