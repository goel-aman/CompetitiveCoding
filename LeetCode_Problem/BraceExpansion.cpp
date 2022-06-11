#include<bits/stdc++.h>
using namespace std;

// 1087. Brace Expansion
// You are given a string s representing a list of words. 
// Each letter in the word has one or more options.

// If there is one option, the letter is represented as is.
// If there is more than one option, then curly braces delimit
//  the options. For example, "{a,b,c}" represents options 
// ["a", "b", "c"].
// For example, if s = "a{b,c}", the first character is always 
// 'a', but the second character can be 'b' or 'c'. The original
//  list is ["ab", "ac"].

// Return all words that can be formed in this manner, sorted in
// lexicographical order.

// Example 1:
// Input: s = "{a,b}c{d,e}f"
// Output: ["acdf","acef","bcdf","bcef"]

// Example 2:
// Input: s = "abcd"
// Output: ["abcd"]
 
// Constraints:
// 1 <= s.length <= 50
// s consists of curly brackets '{}', commas ',', and lowercase 
// English letters.
// s is guaranteed to be a valid input.
// There are no nested curly brackets.
// All characters inside a pair of consecutive opening and ending curly
//  brackets are different.

class Solution {
    vector<string> res;
public:
    vector<string> getStrings(string withoutCurly){
        vector<string> temp;
        string value = "";
        for(int i=0;i<withoutCurly.length();i++){
            if(withoutCurly[i] == ','){
                temp.push_back(value);
                value = "";
            }else{
                value += withoutCurly[i];
            }
        }
        if(value != ""){
            temp.push_back(value);
        }
        return temp;
    }
    
    void getAnswer(vector<vector<string>>& temp,int index,string currentString){
        int tempLength = temp.size();
        if(index == temp.size()){
            res.push_back(currentString);
            return ;
        }
        
        for(int i=0;i<temp[index].size();i++){
            getAnswer(temp,index + 1,(currentString + temp[index][i]));
        }
    }
    
    vector<string> expand(string s) {
        vector<vector<string>> temp;
        string word = "";
        bool openCurly = false;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '{'){
                if(word != ""){
                    temp.push_back({word});
                }
                word = "";
                openCurly = true;
                continue;
            }
            
            if(openCurly == true){
                if(s[i] == '}'){
                    openCurly = false;
                    temp.push_back(getStrings(word));
                    word = "";
                }else{
                    word += s[i];
                }
            }else{
                word += s[i];
            }
        }
        
        if(word != ""){
            temp.push_back({word});
        }
        
        getAnswer(temp,0,"");
        sort(res.begin(),res.end());
        return res;
    }
};