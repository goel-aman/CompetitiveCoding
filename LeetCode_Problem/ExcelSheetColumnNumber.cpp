// 171. Excel Sheet Column Number

// Given a string columnTitle that represents the column title as appear 
// in an Excel sheet, return its corresponding column number.
// For example:
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 
// Example 1:
// Input: columnTitle = "A"
// Output: 1

// Example 2:
// Input: columnTitle = "AB"
// Output: 28

// Example 3:
// Input: columnTitle = "ZY"
// Output: 701

// Example 4:
// Input: columnTitle = "FXSHRXW"
// Output: 2147483647
 
// Constraints:
// 1 <= columnTitle.length <= 7
// columnTitle consists only of uppercase English letters.
// columnTitle is in the range ["A", "FXSHRXW"].


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int  columnTitleLength = columnTitle.length();
        long long p = 1;
        int ans = 0;
        for(int i = columnTitleLength - 1;i >= 0;i--){
            long long val = columnTitle[i] - 'A' + 1;
            ans += val * p;
            p = p * 26;
        }
        return (int) ans;
    }
};