// 1220. Count Vowels Permutation

// Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

// Example 1:
// Input: n = 1
// Output: 5
// Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

// Example 2:
// Input: n = 2
// Output: 10
// Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

// Example 3: 
// Input: n = 5
// Output: 68
 
// Constraints:
// 1 <= n <= 2 * 10^4

#include<bits/stdc++.h>
using namespace std;

class Solution {
    char arr[5] = {'a','e','i','o','u'};
    unordered_map<char,int> um;
    int mod = 1000000007;
    int dp[20001][6];
public:
    Solution(){
        um['a'] = 0;
        um['e'] = 1;
        um['i'] = 2;
        um['o'] = 3;
        um['u'] = 4;
        um['!'] = 5;

        for(int i=0;i<20001;i++){
            for(int j=0;j<6;j++){
                dp[i][j] =  -1;
            }
        }
    }

    int countVowelPermutation(int n,char lastchar){
        if(n == 0){
            return 1;
        }
        if(dp[n][um[lastchar]] != -1){
            return dp[n][um[lastchar]];
        }
        int ans = 0;
        if(lastchar == '!'){
            for(int i=0;i<5;i++){
                ans = (ans + countVowelPermutation(n - 1,arr[i])) % mod;
            }
            return dp[n][um[lastchar]] = ans;
        }
        
        if(lastchar == 'a'){
            return  dp[n][um[lastchar]] = countVowelPermutation(n - 1,'e');
        }

        if(lastchar == 'e'){
            return dp[n][um[lastchar]] = ((countVowelPermutation(n - 1,'a') + countVowelPermutation(n - 1,'i'))%mod);

        }

        if(lastchar == 'i'){
            int ans = 0;
            for(int i=0;i<5;i++){
                if(arr[i] != 'i'){
                    ans = (ans +  countVowelPermutation(n - 1, arr[i])) %mod;
                }
            }
            return dp[n][um[lastchar]] = ans;
        }

        if(lastchar == 'o'){
            return dp[n][um[lastchar]] = ((countVowelPermutation(n - 1,'i') + countVowelPermutation(n - 1,'u'))%mod);
        }

        if(lastchar == 'u'){
            return dp[n][um[lastchar]] = countVowelPermutation(n - 1,'a');
        }
        return 0;
    }
    
    int countVowelPermutation(int n) {
        return countVowelPermutation(n,'!');
    }
};