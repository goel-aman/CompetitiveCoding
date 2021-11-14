#include<bits/stdc++.h>
using namespace std;

// 1717. Maximum Score From Removing Substrings
// You are given a string s and two integers x and y.
//  You can perform two types of operations any number
//  of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it 
// becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it
//  becomes "cabxe".
// Return the maximum points you can gain after applying 
// the above operations on s.

// Example 1:
// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, 
// s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, 
// s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, 
// s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, 
// s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.

// Example 2:
// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20
 
// Constraints:
// 1 <= s.length <= 105
// 1 <= x, y <= 104
// s consists of lowercase English letters.

class Solution {
public:
    bool isAbOrBa(string s){
        int sLength = s.length();
        for(int i=0;i<sLength - 1;i++){
            if(s.substr(i,2) == "ab" || s.substr(i,2) == "ba"){
                return true;
            }
        }
        return false;
    }

    bool isAb(string s){
        int sLength = s.length();
        for(int i=0;i<sLength - 1;i++){
            if(s.substr(i,2) == "ab"){
                return true;
            }
        }
    }

    bool isBa(string s){
        int sLength = s.length();
        for(int i=0;i<sLength - 1;i++){
            if(s.substr(i,2) == "ba"){
                return true;
            }
        }
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        while(isAbOrBa){
            if(x > y){
                while(isAb(s)){
                    int index = -1;
                    for(int i=0;i<s.length() - 1;i++){
                        if(s.substr(i,2) == "ab"){
                            index = i;
                            break;
                        }
                    }
                    s = s.substr(0,index) + s.substr(index + 2);
                    ans += x;
                }

                while(isBa(s)){
                    int index = -1;
                    for(int i=0;i<s.length() - 1;i++){
                        if(s.substr(i,2) == "ba"){
                            index = i;
                            break;
                        }
                    }
                    s = s.substr(0,index) + s.substr(index + 2);
                }
            }else{
                while(isBa(s)){
                    int index = -1;
                    for(int i=0;i<s.length() - 1;i++){
                        if(s.substr(i,2) == "ba"){
                            index = i;
                            break;
                        }
                    }
                    s = s.substr(0,index) + s.substr(index + 2);
                }
                while(isAb(s)){
                    int index = -1;
                    for(int i=0;i<s.length() - 1;i++){
                        if(s.substr(i,2) == "ab"){
                            index = i;
                            break;
                        }
                    }
                    s = s.substr(0,index) + s.substr(index + 2);
                    ans += x;
                }
            } 
        }
    }
};