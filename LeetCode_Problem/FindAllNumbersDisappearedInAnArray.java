import java.util.*;
import java.io.*;

// 448. Find All Numbers Disappeared in an Array
// Given an array nums of n integers where nums[i] is in the
//  range [1, n], return an array of all the integers in the
//  range [1, n] that do not appear in nums.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// Example 2:
// Input: nums = [1,1]
// Output: [2]
 
// Constraints:
// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
// Follow up: Could you do it without extra space and in O(n)
//  runtime? You may assume the returned list does not count 
// as extra space.

public class FindAllNumbersDisappearedInAnArray {
    
}

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int numsLength = nums.length;

        for(int i=0;i<numsLength;i++){
            int value = Math.abs(nums[i]) - 1;
            nums[value] = (nums[value] > 0) ? -nums[value] : nums[value];
        }

        List<Integer> ret = new ArrayList<Integer>();
        for(int i=0;i<numsLength;i++){
            if(nums[i] > 0){
                ret.add(i + 1);
            }
        }

        return ret;
    }
}
