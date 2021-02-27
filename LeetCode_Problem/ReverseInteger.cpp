// 7. Reverse Integer

// Given a signed 32-bit integer x, return x with its digits reversed.
//  If reversing x causes the value to go outside the signed 32-bit 
// integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers
//  (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
// Example 4:

// Input: x = 0
// Output: 0
 
// Constraints:
// -231 <= x <= 231 - 1

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        long long int value = (long long)((long long)1<<31);
        long long int low = -1 * value;
        long long int high = value - 1;
        int negative = 0;
        if(x < 0){
            negative = 1;
        }
        if(x == low){
            return 0;
        }
        x = -1 * x;
        string number = to_string(x);
        std::reverse(number.begin(),number.end());
        if(stoll(number) > high || stoll(number) < low){
            return 0;
        }
        int i=0;
        int length = number.length();
        while(true){
            if(number[i] == '0'){
                number = number.substr(1);
                length--;
                if(length == 0){
                    break;
                }
            }
            else{
                break;
            }
        }
        if(number.size() == 0){
            return 0;
        }
        
        if(negative){
            return (-1 *stoi(number));
        }
        return stoi(number);
    }
};