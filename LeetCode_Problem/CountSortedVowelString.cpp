// 1641. Count Sorted Vowel Strings

// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
// Example 2:

// Input: n = 2
// Output: 15
// Explanation: The 15 sorted strings that consist of vowels only are
// ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
// Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
// Example 3:

// Input: n = 33
// Output: 66045
 

// Constraints:

// 1 <= n <= 50 


// Solution
#include<bits/stdc++.h>
using namespace std;

class Solution {
    char arr[5] = {'a','e','i','o','u'};
    
public:
    
    int count(int length,char lastchar){
        if(length == 0){
            return 1;
        }
        int ans = 0;
        int i =0;
        for(;i<5;i++){
            if(lastchar == arr[i]){
                break;;
            }
        }
        
        for(;i<5;i++){
            ans += count(length - 1,arr[i]);
        }
        return ans;
    }
    
    int countVowelStrings(int n) {
        int ans = 0;
        for(int i=0;i<5;i++){
            ans += count(n - 1,arr[i]);
        }
        return ans;
    }
};