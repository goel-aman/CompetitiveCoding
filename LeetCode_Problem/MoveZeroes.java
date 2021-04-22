// import java.util.*;
class MoveZeroes{

    public void moveZeroes(int[] nums) {
        int numsLength = nums.length;
        int i = 0;
        for(int m = 0; m < numsLength;m++){
            if(nums[m] != 0){
                nums[i] = nums[m];
                i++;
                continue;
            }
        }

        for(;i<numsLength;i++){
            nums[i] = 0;
        }
        return ;
    }
}