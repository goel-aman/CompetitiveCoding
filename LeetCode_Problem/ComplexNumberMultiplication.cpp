#include<bits/stdc++.h>
using namespace std;

// 537. Complex Number Multiplication
// A complex number can be represented as a string 
// on the form "real+imaginaryi" where:
// real is the real part and is an integer in the 
// range [-100, 100].
// imaginary is the imaginary part and is an integer
//  in the range [-100, 100].
// i2 == -1.
// Given two complex numbers num1 and num2 as strings,
//  return a string of the complex number that represents
//  their multiplications.

// Example 1:
// Input: num1 = "1+1i", num2 = "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and 
// you need convert it to the form of 0+2i.

// Example 2:
// Input: num1 = "1+-1i", num2 = "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and
//  you need convert it to the form of 0+-2i.
 
// Constraints:
// num1 and num2 are valid complex numbers.

class Solution {
public:
    int getIntegerPart(string num){
        int numLength = num.length();
        int breakPoint = 0;
        for(int i=0;i<numLength;i++){
            if(num[i] == '+'){
                breakPoint = i;
                break;
            }
        }

        string val = num.substr(0,breakPoint);
        if(val[0] == '-'){
            int number = (-1 * stoi(val.substr(1)));
            return number;
        }

        return stoi(val);
    }

    int getComplexPart(string num){
        int numLength = num.length();
        int breakPoint = 0;
        for(int i=0;i<numLength;i++){
            if(num[i] == '+'){
                breakPoint = i;
                break;
            }          
        }

        string val = num.substr(breakPoint + 1);
        if(val[0] == '-'){
            int valLength = val.length();
            int value = stoi(val.substr(1,valLength - 2));
            return (-1* value);
        }

        return stoi(val.substr(0,val.length() - 1));
    }

    string complexNumberMultiply(string num1, string num2) {
        int num1Real = getIntegerPart(num1);
        int num2Real = getIntegerPart(num2);
        int num1Complex = getComplexPart(num1);
        int num2Complex = getComplexPart(num2);

        int realPart = (num1Real * num2Real) - (num2Complex * num1Complex);
        int imaginaryPart = (num1Real * num2Complex) + (num1Complex * num2Real);
        string ans = "";
        if(realPart < 0){
            ans += "-";
        }

        ans += to_string(realPart);
        ans += "+";
        if(imaginaryPart < 0){
            ans += "-";
        }
        ans += to_string(imaginaryPart);
        ans += "i";
        return ans;
    }
};