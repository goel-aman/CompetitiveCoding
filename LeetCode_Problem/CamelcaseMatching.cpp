#include<bits/stdc++.h>
using namespace std;

// 1023. Camelcase Matching
// Given an array of strings queries and a string pattern, 
// return a boolean array answer where answer[i] is true if
//  queries[i] matches pattern, and false otherwise.

// A query word queries[i] matches pattern if you can insert
//  lowercase English letters pattern so that it equals the
//  query. You may insert each character at any position and
// you may not insert any characters.

// Example 1:
// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer"
// ,"ForceFeedBack"], pattern = "FB"
// Output: [true,false,true,true,false]
// Explanation: "FooBar" can be generated like this
//  "F" + "oo" + "B" + "ar".
// "FootBall" can be generated like this "F" + "oot" + "B" + "all".
// "FrameBuffer" can be generated like this
//  "F" + "rame" + "B" + "uffer".

// Example 2:
// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer",
// "ForceFeedBack"], pattern = "FoBa"
// Output: [true,false,true,false,false]
// Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
// "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

// Example 3:
// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer"
// ,"ForceFeedBack"], pattern = "FoBaT"
// Output: [false,true,false,false,false]
// Explanation: "FooBarTest" can be generated like 
// this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 
// Constraints
// 1 <= pattern.length, queries.length <= 100
// 1 <= queries[i].length <= 100
// queries[i] and pattern consist of English letters.

class Solution {
public:
    bool verify(string &s1,string &pattern){
        int s1Length = s1.length();
        int patternLength = pattern.length();
        if(patternLength > s1Length){
            return false;
        }

        if(patternLength == s1Length){
            if(pattern == s1){
                return true;
            }
            return false;
        }


        int i=0, j = 0;
        for(;i<s1Length;i++){
            if(s1[i] == pattern[j]){
                j++;
                if(j == patternLength){
                    break;
                }
            }
        }

        if(j == patternLength){
            return true;
        }
        return false;
    }

    vector<string> wordBreak(string &input){
        vector<string> ret;
        int inputLength = input.length();
        string ans = "";
        int breakPoint = 0;
        if(isupper(input[0]) == false){
            for(int i=0;i<inputLength;i++){
                if(isupper(input[i])){
                    breakPoint = i;
                    ans = input.substr(0,breakPoint);
                    break;
                }
            }
        }
        
        ans += input[breakPoint];
        for(int i=breakPoint + 1;i<inputLength;i++){
            if(isupper(input[i])){
                ret.push_back(ans);
                ans = "";
                ans += input[i];
            }else{
                ans += input[i];
            }
        }
        
        ret.push_back(ans);
        return ret;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<string> patternBreak;
        int patternLength = pattern.length();
        int breakPoint = 0;
        string ans = "";
        if(isupper(pattern[0]) == false){
            for(int i=0;i<patternLength;i++){
                if(isupper(pattern[i])){
                    breakPoint = i;
                    ans = pattern.substr(0,i);
                    break;
                }
            }
        }
        ans += pattern[breakPoint];
        for(int i=breakPoint + 1;i<patternLength;i++){
            if(isupper(pattern[i])){
                patternBreak.push_back(ans);
                ans = "";
                ans += pattern[i];
            }
            else{
                ans += pattern[i];
            }
        }
        patternBreak.push_back(ans);
    
        int patternBreakLength = patternBreak.size();

        vector<bool> anss;
        for(int i=0;i<queries.size();i++){
            // queries[i] = transform(queries[i]);
            vector<string> vec = wordBreak(queries[i]);
            if(vec.size() != patternBreakLength){
                anss.push_back(false);
                continue;
            }else{
                bool gotAnswer = true;
                for(int j=0;j<vec.size();j++){
                    bool val = verify(vec[j],patternBreak[j]);
                    if(val == false){
                        gotAnswer = false;
                        break;
                    }                  
                }


                if(gotAnswer){
                    anss.push_back(true);
                    continue;
                }

                anss.push_back(false);
            }
        }
        return anss;
    }
};