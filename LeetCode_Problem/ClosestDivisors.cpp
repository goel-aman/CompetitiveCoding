#include<bits/stdc++.h>
using namespace std;

// 1362. Closest Divisors
// Given an integer num, find the closest two integers in absolute
//  difference whose product equals num + 1 or num + 2.
// Return the two integers in any order.

// Example 1:
// Input: num = 8
// Output: [3,3]
// Explanation: For num + 1 = 9, the closest divisors are 3 & 3,
//  for num + 2 = 10, the closest divisors are 2 & 5,
//  hence 3 & 3 is chosen.

// Example 2:
// Input: num = 123
// Output: [5,25]

// Example 3:
// Input: num = 999
// Output: [40,25]
 
// Constraints:
// 1 <= num <= 10^9

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num + 1, num2 = num + 2;
        int ans = INT_MAX,first,second;
        for(int i=1;i<=sqrt(num2);i++){
            if(num1%i == 0){
                int firstNumber = num1/i,secondNumber = i;
                int difference = abs(firstNumber - secondNumber);
                if(difference < ans){
                    ans = difference;
                    first = firstNumber;
                    second = secondNumber;
                }
            }

            if(num2%i == 0){
                int firstNumber = num2/i,secondNumber = i;
                int difference = abs(firstNumber - secondNumber);
                if(difference < ans){
                    ans = difference;
                    first = firstNumber;
                    second = secondNumber;
                }    
            }
        }
        return {first,second};
    }
};