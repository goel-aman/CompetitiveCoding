#include<bits/stdc++.h>
using namespace std;

// 372. Super Pow
// Your task is to calculate ab mod 1337 where a is 
// a positive integer and b is an extremely large positive
//  integer given in the form of an array.

// Example 1:
// Input: a = 2, b = [3]
// Output: 8

// Example 2:
// Input: a = 2, b = [1,0]
// Output: 1024

// Example 3:
// Input: a = 1, b = [4,3,3,8,5,2]
// Output: 1

// Example 4:
// Input: a = 2147483647, b = [2,0,0]
// Output: 1198
 
// Constraints:
// 1 <= a <= 231 - 1
// 1 <= b.length <= 2000
// 0 <= b[i] <= 9
// b doesn't contain leading zeros.

class Solution {
    int k = 1337;
public:
    int submod(int a,int b){
        if(b == 0){
            return 1;
        }
        a %= k;
        int result = 1;
        for(int i=0;i<b;i++){
            result = (result * a)%k;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        int bLength = b.size();
        if(bLength == 0){
            return 1;
        }

        int lastDigit = b[bLength - 1];
        b.pop_back();
        return (submod(superPow(a,b),10) * submod(a,lastDigit))%k;
    }
};