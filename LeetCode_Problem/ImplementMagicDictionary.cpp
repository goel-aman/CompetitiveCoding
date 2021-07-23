#include<bits/stdc++.h>
using namespace std;

// 676. Implement Magic Dictionary
// Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.


// Implement the MagicDictionary class:

// MagicDictionary() Initializes the object.
// void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
// bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
 

// Example 1:

// Input
// ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
// [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
// Output
// [null, null, false, true, false, false]

// Explanation
// MagicDictionary magicDictionary = new MagicDictionary();
// magicDictionary.buildDict(["hello", "leetcode"]);
// magicDictionary.search("hello"); // return False
// magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
// magicDictionary.search("hell"); // return False
// magicDictionary.search("leetcoded"); // return False
 

// Constraints:

// 1 <= dictionary.length <= 100
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case English letters.
// All the strings in dictionary are distinct.
// 1 <= searchWord.length <= 100
// searchWord consists of only lower-case English letters.
// buildDict will be called only once before search.
// At most 100 calls will be made to search.

class TrieNode{
    public:
    unordered_map<char,TrieNode*> um;
   
    int isEnding = false;
};

class MagicDictionary {
    TrieNode* root;
    // unordered_map<string,bool> extra;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void insert(string str,TrieNode* root){
        int strLength = str.length();
        if(strLength == 0){
            root->isEnding = true;
            return;
        }

        if(root->um.count(str[0]) > 0){
            insert(str.substr(1),root->um[str[0]]);
            return ;
        }      

        root->um[str[0]] = new TrieNode();
        insert(str.substr(1),root->um[str[0]]);
        return;
    }

    void buildDict(vector<string> dictionary) {
        int n = dictionary.size();
        for(int i=0;i<n;i++){
            insert(dictionary[i],root);
            // extra[dictionary[i]] = true;
        }

        return ;
    }
    
    bool search(string searchWord,int exemption,TrieNode* root){
        int searchWordLength = searchWord.length();
        if(exemption > 1){
            return false;
        }

        if(searchWordLength == 0 ){
            if(root->isEnding == true && exemption == 1){
                return true;
            }
            return false;
        }

        for(auto var : root->um){
            if(var.first == searchWord[0]){
                bool val = search(searchWord.substr(1),exemption,var.second);
                if(val){
                    return true;
                }
                continue;
            }
            
            bool val = search(searchWord.substr(1),exemption + 1,var.second);
            if(val == true){
                return true;
            }
        }
        return false;
    }

    bool search(string searchWord) {
        return search(searchWord,0,root);
    }
};