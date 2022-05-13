#include<bits/stdc++.h>
using namespace std;

// 1100. Find K-Length Substrings With No Repeated Characters
// Given a string s and an integer k, return the number of 
// substrings in s of length k with no repeated characters.

// Example 1:
// Input: s = "havefunonleetcode", k = 5
// Output: 6
// Explanation: There are 6 substrings they are: 'havef',
// 'avefu','vefun','efuno','etcod','tcode'.

// Example 2:
// Input: s = "home", k = 5
// Output: 0
// Explanation: Notice k can be larger than the length of s.
// In this case, it is not possible to find any substring.
 
// Constraints:
// 1 <= s.length <= 104
// s consists of lowercase English letters.
// 1 <= k <= 104

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int arr[26];
        for(int i=0;i<26;i++){
            arr[i] = 0;
        }
        int sLength = s.length();
        int count = 0;
        int j = 0;
        for(int i=0;i<sLength;i++){
            if(i < k - 1){
                int position = s[i] - 'a';
                arr[position]++;
                // continue;
            }
            else if(i == k - 1){
                int position = s[i] - 'a';
                arr[position]++;
                bool isPossible = true;
                for(int iter = 0;iter < 26;iter++){
                    if(arr[iter] > 1){
                        isPossible = false;
                        break;
                    }
                }
                if(isPossible){
                    count++;
                }
            }else{
                int position = s[j] - 'a';
                arr[position]--;
                j++;
                position = s[i] - 'a';
                arr[position]++;
                bool isPossible = true;
                for(int iter = 0;iter < 26;iter++){
                    if(arr[iter] > 1){
                        isPossible = false;
                        break;
                    }
                }
                if(isPossible){
                    count++;
                }
            }
        }
        return count;
    }
};