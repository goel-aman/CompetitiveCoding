#include<bits/stdc++.h>
using namespace std;

// 211. Design Add and Search Words Data Structure

// Design a data structure that supports adding new words 
// and finding if a string matches any previously added string.
// Implement the WordDictionary class:
// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be
//  matched later.
// bool search(word) Returns true if there is any string in the 
// data structure that matches word or false otherwise. word may
//  contain dots '.' where dots can be matched with any letter.
 
// Example:
// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 

// Constraints:
// 1 <= word.length <= 500
// word in addWord consists lower-case English letters.
// word in search consist of  '.' or lower-case English letters.
// At most 50000 calls will be made to addWord and search.

class WordDictionary {
    bool isword = false;
    unordered_map<char,WordDictionary*> um;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int wordLength = word.length();
        int i=0;
        WordDictionary* node = this;
        while(i < wordLength){
            if(node->um.count(word[i]) > 0){
                node = node->um[word[i]];
            }else{
                node->um[word[i]] = new WordDictionary();
                node = node->um[word[i]];
            }
            i++;
        }
        node->isword = true;
        return ;
    }

    bool search(string& word,int index,WordDictionary* node){
        int wordLength = word.length();
        if(index == wordLength){
            if(node->isword == true){
                return true;
            }else{
                return false;
            }
        }

        if(word[index] == '.'){
            for(auto var : node->um){
                bool ans = search(word,index + 1,var.second);
                if(ans){
                    return true;
                }
            }
            return false;
        }

        if(node->um.count(word[index]) > 0){
            return search(word,index + 1,node->um[word[index]]);
        }
        return false;
    }
    
    bool search(string word) {
        WordDictionary* node = this;
        return search(word,0,node);
    }
};