import java.util.*;
import java.io.*;

// 349. Intersection of Two Arrays
// Given two integer arrays nums1 and nums2, return an 
// array of their intersection. Each element in the 
// result must be unique and you may return the result 
// in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

public class IntersectionOfTwoArrays {
    
}

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer,Boolean> map = new HashMap<Integer,Boolean>();
        int nums1Length = nums1.length;
        int nums2Length = nums2.length;
        Set<Integer> unique = new HashSet<Integer>();

        for(int i=0;i<nums1Length;i++){
            map.put(nums1[i],true);
        }

        for(int i=0;i<nums2Length;i++){
            if(map.containsKey(nums2[i])){
                unique.add(nums2[i]);
            }
        }

        int arr[] = new int[unique.size()];
        int i= 0;
        for(int var : unique){
            arr[i] = var;
            i++;
        }
        return arr;
    }
}