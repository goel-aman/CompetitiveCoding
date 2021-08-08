#include<bits/stdc++.h>
using namespace std;

// 984. String Without AAA or BBB
// Given two integers a and b, return any string
//  s such that:
// s has length a + b and contains exactly a 'a' letters,
//  and exactly b 'b' letters,
// The substring 'aaa' does not occur in s, and
// The substring 'bbb' does not occur in s.

// Example 1:
// Input: a = 1, b = 2
// Output: "abb"
// Explanation: "abb", "bab" and "bba" are all correct answers.

// Example 2:
// Input: a = 4, b = 1
// Output: "aabaa"
 
// Constraints:
// 0 <= a, b <= 100
// It is guaranteed such an s exists for the given a and b.

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        char prevChar = '0';
        if(a > b){
            prevChar = 'b';
        }else{
            prevChar = 'a';
        }
        
        while(a > 0 && b > 0){
            if(prevChar != 'a'){
                if(a > 1 && a >= b){
                    ans += "aa";
                    a -= 2;
                }
                else{
                    ans += "a";
                    a -= 1;
                }
                ans += "b";
                b -= 1;
                prevChar = 'b';
                continue;
            }else{
                if(b > 1 && b >= a){
                    ans += "bb";
                    b -= 2;
                }else{
                    ans += "b";
                    b -= 1;
                }
                ans += "a";
                a -= 1;
                prevChar = 'a';
                continue;
            }
        }      
        
        while(a > 0){
            ans += "a";
            a -= 1;
        }
        
        while(b > 0){
            ans += "b";
            b -= 1;
        }
        return ans;
    }
};