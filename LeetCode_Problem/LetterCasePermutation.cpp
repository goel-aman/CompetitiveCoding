#include<bits/stdc++.h>
using namespace std;

// 784. Letter Case Permutation

// Given a string s, we can transform every letter individually to be 
// lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. You can return
//  the output in any order.

// Example 1:
// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Example 2:
// Input: s = "3z4"
// Output: ["3z4","3Z4"]

// Example 3:
// Input: s = "12345"
// Output: ["12345"]

// Example 4:
// Input: s = "0"
// Output: ["0"]
 
// Constraints:
// s will be a string with length between 1 and 12.
// s will consist only of letters or digits.

class Solution {
    int sLength;
public:
    void letterCase(string &s,vector<string> &res,int index,string &current){
        if(index == sLength){
            res.push_back(current);
            return ;
        }

        if(isalpha(s[index])){
            // cout<<"value of touppper is : "<<toupper(s[index])<<endl;
            current += toupper(s[index]);
            letterCase(s,res,index + 1,current);
            current.pop_back();
        }

        current += tolower(s[index]);
        letterCase(s,res,index + 1,current);
        current.pop_back();
        return;
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        sLength = s.length();
        int index = 0;
        string current = "";
        letterCase(s,res,index,current);
        return res;
    }
};