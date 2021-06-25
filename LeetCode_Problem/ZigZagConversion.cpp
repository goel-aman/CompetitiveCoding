#include<bits/stdc++.h>
using namespace std;

// 6. ZigZag ConversionShare
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
// number of rows like this: (you may want to display this pattern in a 
// fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given 
// a number of rows:
// string convert(string s, int numRows);
 
// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"
 
// Constraints:
// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

class Solution {
public:
    string convert(string s, int numRows) {
        int sLength = s.length();
        vector<string> vec(numRows,"");
        int i=0;
        int col = 0;
        while(i < sLength){
            if(col%2 == 0){
                for(int row = 0;row < numRows;row++){
                    if(col%2 == 0){
                        if(i >= sLength){
                         break;
                        }
                        vec[row].push_back(s[i]);
                        i++;
                        continue;
                    }
                }
                col++;
                continue;
            }else{
                for(int row = numRows - 1;row >=0;row--){
                    if(row == 0 || row == numRows - 1){
                        continue;
                    }
                    
                    if(i >= sLength){
                        break;
                    }
                    vec[row].push_back(s[i]);
                    i++;
                }
                col++;
            }
        }
        string ans = "";
        for(int i=0;i<vec.size();i++){
            ans += vec[i];
        }
        return ans;
    }
};