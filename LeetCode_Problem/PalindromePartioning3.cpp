// 1278. Palindrome Partitioning III

// You are given a string s containing lowercase letters and an integer k. You need to :
// First, change some characters of s to other lowercase English letters.
// Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
// Return the minimal number of characters that you need to change to divide the string.

// Example 1:
// Input: s = "abc", k = 2
// Output: 1
// Explanation: You can split the string into "ab" and "c", and change 1 character 
// in "ab" to make it palindrome.

// Example 2:
// Input: s = "aabbc", k = 3
// Output: 0
// Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.

// Example 3:
// Input: s = "leetcode", k = 8
// Output: 0
 
// Constraints
// 1 <= k <= s.length <= 100.
// s only contains lowercase English letters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ** dp;
    
    bool isPalindrome(string input){
        int inputLength = input.length();
        if(inputLength == 0 || inputLength == 1){
            return true;
        }

        int length = inputLength / 2;
        for(int i=0;i<length;i++){
            if(input[i] == input[inputLength - i - 1]){
                continue;             
            }
            else{
                return false;
            }
        }
        return true;
    }

    int makePalindrome(string input){
        int inputLength = input.length();
        int length = inputLength / 2;
        int value = 0;
        for(int i=0;i<length;i++){
            if(input[i] != input[inputLength - i - 1]){
                value++;
            }
        }
        return value;
    }
public:
    Solution(){
        dp = new int*[101];
        for(int i=0;i<=100;i++){
            dp[i] = new int[101];
            for(int j=0;j<=100;j++){
                dp[i][j] = -1;
            }
        }
        // dp = new int*[101];
    }
    
    int palindromePartition(string s, int k) {
        int sLength = s.length();

        if(k == sLength){
            return 0;
        }
        if(sLength < k){
            return -1000;
        }
        if(k == 1){
            return makePalindrome(s);
        }
        
        if(dp[sLength][k]  != -1){
            return dp[sLength][k];
        }
        
        
        int finalAns = INT_MAX;
        for(int i=0;i<=(sLength - k);i++){
            string left = s.substr(i + 1);
            string curr = s.substr(0,i + 1);
            
            if(isPalindrome(curr)){
                int findValue = palindromePartition(left,k - 1);
                finalAns = min(finalAns,findValue);
            }
            else{
                int val = makePalindrome(curr);
                int findValue = palindromePartition(left,k - 1) + val;
                finalAns = min(finalAns,findValue);
            }
        }
        return dp[sLength][k] = finalAns;      
    }
};