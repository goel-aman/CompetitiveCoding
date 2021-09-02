#include<bits/stdc++.h>
using namespace std;

// Four Divisors

// Given an integer array nums, return the sum of divisors 
// of the integers in that array that have exactly four divisors.
//  If there is no such integer in the array, return 0.

// Example 1:
// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.

// Example 2:
// Input: nums = [21,21]
// Output: 64

// Example 3:
// Input: nums = [1,2,3,4,5]
// Output: 0

// Constraints:
// 1 <= nums.length <= 104
// 1 <= nums[i] <= 105


class Solution {
public:
    int findDivisors(int number){
        int count = 0;
        int sum = 0;
        for(int i=1;i<=sqrt(number);i++){
            if(number%i == 0 && number/i == i){
                count++;
                sum += i;
                continue;
            }
            else{
                if(number%i == 0){
                    count += 2;
                    sum += i;
                    sum += (number/i);
                    if(count > 4){
                        break;
                    }
                }
            }
        }
        if(count == 4){
            return sum;
        }
        return -1;
    }

    int sumFourDivisors(vector<int>& nums) {
        int numsLength = nums.size();
        int ans = 0;
        for(int i=0;i<numsLength;i++){
            int value = findDivisors(nums[i]);
            if(value != -1){
                ans += value;
            }          
        }
        return ans;
    }
};