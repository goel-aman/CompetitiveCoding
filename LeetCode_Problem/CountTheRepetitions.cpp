// 466. Count The Repetitions

// Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".

// On the other hand, we define that string s1 can be obtained from string s2 if we 
// can remove some characters from s2 such that it becomes s1. For example, “abc” can
//  be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

// You are given two non-empty strings s1 and s2 (each at most 100 characters long) 
// and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2,
//  where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.

// Example:

// Input:
// s1="acb", n1=4
// s2="ab", n2=2

// Return:
// 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getAnswer(string fulls1,string s2){
        int length = fulls1.length();
        int s2length = s2.length();
        if(length == 0){
            return 0;
        }

        if(fulls1 == s2){
            return 1;
        }

        if(length < s2length){
            return 0;
        }
        if(length == s2length){
            if(fulls1 != s2){
                return 0;
            }
            return 1;
        }
        // i for fulls1
        // j for s2
        int j=0;
        int i=0;
        while(i < length && j < s2length){
            if(fulls1[i] == s2[j]){
                i++;
                j++;
                continue;
            }
            i++;
        }
        if(j == s2length){
            return 1 + getAnswer(fulls1.substr(i),s2);
        }

        if(i == length){
            return 0;
        }
        return 0;
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string fulls1 = "";
        int tempn1 = n1;
        while(tempn1 > 0){
            fulls1 += s1;
            tempn1--; 
        }
        return getAnswer(fulls1,s2);
    }
};