#include<bits/stdc++.h>
using namespace std;

// 1839. Longest Substring Of All Vowels in Order
// A string is considered beautiful if it satisfies the following conditions:
// Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at
//  least once in it.
// The letters must be sorted in alphabetical order (i.e. all 'a's before
//  'e's, all 'e's before 'i's, etc.).
// For example, strings "aeiou" and "aaaaaaeiiiioou" are considered
//  beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
// Given a string word consisting of English vowels, return the
//  length of the longest beautiful substring of word. If no such
//  substring exists, return 0.
// A substring is a contiguous sequence of characters in a string.

// Example 1:
// Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
// Output: 13
// Explanation: The longest beautiful substring in word is
//  "aaaaeiiiiouuu" of length 13.

// Example 2:
// Input: word = "aeeeiiiioooauuuaeiou"
// Output: 5
// Explanation: The longest beautiful substring in word is
//  "aeiou" of length 5.

// Example 3:
// Input: word = "a"
// Output: 0
// Explanation: There is no beautiful substring, so return 0.

// Constraints:
// 1 <= word.length <= 5 * 105
// word consists of characters 'a', 'e', 'i', 'o', and 'u'.

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int wordLength = word.length();
        int a=0,e=0,i=0,o=0,u=0;
        int ans = 0, j = 0,value = 0;
        while(j < wordLength){
            while( j<wordLength && word[j] == 'a'){
                a++;
                j++;
            }

            while(j< wordLength && word[j] == 'e'){
                e++;
                j++;
            }

            while(j < wordLength && word[j] == 'i'){
                i++;
                j++;
            }

            while(j < wordLength && word[j] == 'o'){
                o++;
                j++;
            }

            while(j < wordLength && word[j] == 'u'){
                u++;
                j++;
            }
            ans = min({a,e,i,o,u});
            if(ans != 0){
                value = max(value,a + e + i + o + u);
            }
            a = 0;e = 0; i = 0;o = 0; u= 0;
        }
        return value;
    }
};