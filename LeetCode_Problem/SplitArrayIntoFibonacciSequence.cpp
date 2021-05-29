#include <bits/stdc++.h>
using namespace std;

// 842. Split Array into Fibonacci Sequence

// You are given a string of digits num, such as "123456579".
// We can split it into a Fibonacci-like sequence [123, 456, 579].

// Formally, a Fibonacci-like sequence is a list f of non-negative
//  integers such that:

// 0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed
// integer type),
// f.length >= 3, and
// f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
// Note that when splitting the string into pieces, each piece must
// not have extra leading zeroes, except if the piece is the number
//  0 itself.
// Return any Fibonacci-like sequence split from num, or return []
//  if it cannot be done.

// Example 1:
// Input: num = "123456579"
// Output: [123,456,579]

// Example 2:
// Input: num = "11235813"
// Output: [1,1,2,3,5,8,13]

// Example 3:
// Input: num = "112358130"
// Output: []
// Explanation: The task is impossible.

// Example 4:
// Input: num = "0123"
// Output: []
// Explanation: Leading zeroes are not allowed,
//  so "01", "2", "3" is not valid.

// Example 5:
// Input: num = "1101111"
// Output: [11,0,11,11]
// Explanation: The output [11, 0, 11, 11] would also be accepted.

// Constraints:
// 1 <= num.length <= 200
// num contains only digits.

class Solution
{
public:
    vector<int> splitIntoFibonacci(string num){
        int numLength = num.length();
        for (int i = 1; i <= min(8,(numLength) / 2); i++){
            for (int j = 1; j <= min(8,(numLength / 2)); j++){
                vector<string> vec;
                string first = num.substr(0, i);
                string second = num.substr(i, j);
                if ((first == "0" && second != "0") || (first != "0" && second == "0") || (first[0] != '0' && second[0] != '0') || (first == "0" && second == "0")){
                    string output = first + second;
                    vec.push_back(first);
                    vec.push_back(second);
                    long long int firstValue = stoll(first);
                    long long int secondValue = stoll(second);

                    while (output.length() < num.length()){
                        long long int nextValue = firstValue + secondValue;
                        vec.push_back(to_string(nextValue));
                        output += to_string(nextValue);
                        firstValue = secondValue;
                        secondValue = nextValue;
                    }

                    if(output == num){
                        vector<int> ans;
                        if(vec.size() == 2){
                            return {};
                        }
                        for(int i=0;i<vec.size();i++){
                            if(stoll(vec[i]) >= INT_MAX){
                                return {};
                            }
                            ans.push_back(stoi(vec[i]));
                        }
                        
                        return ans;
                    }
                }
            }
        }
        return {};
    }
};