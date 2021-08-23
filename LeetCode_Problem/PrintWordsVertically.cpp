#include<bits/stdc++.h>
using namespace std;

// 1324. Print Words Vertically
// Given a string s. Return all the words vertically in 
// the same order in which they appear in s.
// Words are returned as a list of strings, complete with 
// spaces when is necessary. (Trailing spaces are not allowed).
// Each word would be put on only one column and that in 
// one column there will be only one word.

// Example 1:
// Input: s = "HOW ARE YOU"
// Output: ["HAY","ORO","WEU"]
// Explanation: Each word is printed vertically. 
//  "HAY"
//  "ORO"
//  "WEU"

// Example 2:
// Input: s = "TO BE OR NOT TO BE"
// Output: ["TBONTB","OEROOE","   T"]
// Explanation: Trailing spaces is not allowed. 
// "TBONTB"
// "OEROOE"
// "   T"

// Example 3:
// Input: s = "CONTEST IS COMING"
// Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 

// Constraints:
// 1 <= s.length <= 200
// s contains only upper case English letters.
// It's guaranteed that there is only one space
//  between 2 words.


class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int sLength = s.length();
        string temp = "";
        int maxWordLength = 0;



        for(int i=0;i<sLength;i++){
            if(s[i] == ' '){
                if(temp.length() > 0){
                    maxWordLength = max(maxWordLength,(int) temp.length());
                    words.push_back(temp);
                }
                temp = "";
            }
            else{
                temp += s[i];
            }
        }    
        if(temp.length() > 0){
            words.push_back(temp);
        }
        maxWordLength = max(maxWordLength,(int) temp.length());
        unordered_map<int,string> um;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            int wordLength = word.length();
            for(int j=0;j<maxWordLength;j++){
                if(j >= wordLength){
                    um[j].push_back(' ');
                }else{
                    um[j].push_back(word[j]);
                }
            }
        }
        vector<string> ans;
        for(int i=0;i<maxWordLength;i++){
            ans.push_back(um[i]);
        }

        for(int i=0;i<ans.size();i++){
            string word = ans[i];
            int index = word.length();
            for(int j=word.length() -1;j>=0;j--){
                if(isalpha(word[j])){
                    index = j;
                    break;
                }
                
            }
            ans[i] = word.substr(0,index + 1);
        }
        return ans;
    }
};