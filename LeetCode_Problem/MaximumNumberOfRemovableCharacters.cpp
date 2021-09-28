#include<bits/stdc++.h>
using namespace std;

// 1898. Maximum Number of Removable Characters
// You are given two strings s and p where p is a subsequence of s.
//  You are also given a distinct 0-indexed integer array removable
//  containing a subset of indices of s (s is also 0-indexed).

// You want to choose an integer k (0 <= k <= removable.length) such
//  that, after removing k characters from s using the first k indices
//  in removable, p is still a subsequence of s. More formally, you
//  will mark the character at s[removable[i]] for each 0 <= i < k, 
// then remove all marked characters and check if p is still a subsequence.

// Return the maximum k you can choose such that p is still a subsequence
// of s after the removals.

// A subsequence of a string is a new string generated from the original 
// string with some characters (can be none) deleted without changing the
//  relative order of the remaining characters.

// Example 1:
// Input: s = "abcacb", p = "ab", removable = [3,1,0]
// Output: 2
// Explanation: After removing the characters at indices 3 and 1, "abcacb"
//  becomes "accb".
// "ab" is a subsequence of "accb".
// If we remove the characters at indices 3, 1, and 0, "abcacb" becomes
//  "ccb", and "ab" is no longer a subsequence.
// Hence, the maximum k is 2.

// Example 2:
// Input: s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
// Output: 1
// Explanation: After removing the character at index 3, "abcbddddd"
//  becomes "abcddddd".
// "abcd" is a subsequence of "abcddddd".

// Example 3:
// Input: s = "abcab", p = "abc", removable = [0,1,2,3,4]
// Output: 0
// Explanation: If you remove the first index in the array removable, 
// "abc" is no longer a subsequence.
 
// Constraints:
// 1 <= p.length <= s.length <= 105
// 0 <= removable.length < s.length
// 0 <= removable[i] < s.length
// p is a subsequence of s.
// s and p both consist of lowercase English letters.
// The elements in removable are distinct.


class Solution {
    unordered_map<int,string> um;
public:
    // p is subsequence of s
    bool isPalindrome(string s,string p){
        int pLength = p.length();
        int sLength = s.length();

        if(pLength > sLength){
            return false;
        }

        if(pLength == sLength && p == s){
            return true;
        }

        if(pLength == sLength && p != s){
            return false;
        }

        int i = 0;
        for(int j = 0;j<sLength;j++){
            if(s[j] == p[i]){
                i++;
            }
            if(i == pLength){
                break;
            }
        }
        if(i == pLength){
            return true;
        }
        return false;
    }
    
    string computeSubString(int index,string s){
        string ans = s.substr(0,index) + s.substr(index + 1);
        return ans;
    }
    
    string getString(int index,vector<int>& removable,string s){
        unordered_map<int,bool> um;
        for(int i=0;i<=index;i++){
            um[removable[i]] = true;
        }

        string newS = "";
        for(int i=0;i<s.length();i++){
            if(!um.count(i)){
                newS += s[i];
            }
        }
        return newS;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int sLength = s.length();
        int pLength = p.length();
        int removableLength = removable.size();

        int start = 0,end = removableLength - 1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            
            string processed = getString(mid,removable,s);
            bool val = isPalindrome(processed,p);
            if(val){
                ans = mid;
                start = mid + 1;
                continue;
            }else{
                end = mid  - 1;
            }
        }
        return ans+1;
    }
};