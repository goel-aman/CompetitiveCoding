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
    string manipulation(string s,char a,char b){
        string ret;
        for(int i=0;i<s.length();i++){
            char current = s[i];
            if(!ret.empty() && ret.back() == a && current == b){
                ret.pop_back();
            }else{
                ret.push_back(current);
            }
        }
        return ret;
    }

    int maximumGain(string s, int x, int y) {
        int sLength = s.length();
        char a = 'a', b = 'b';
        if(y > x){
            swap(a,b);
            swap(x,y);
        }        

        string first = manipulation(s,a,b),second = manipulation(first,b,a);
        int ans = ((s.size() - first.size())/2) * x + ((first.size() - second.size())/2) * y;
        return ans;
    }
};