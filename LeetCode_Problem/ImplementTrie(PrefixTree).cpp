#include<bits/stdc++.h>
using namespace std;

// 208. Implement Trie (Prefix Tree)

// A trie (pronounced as "try") or prefix tree is a tree data structure used 
// to efficiently store and retrieve keys in a dataset of strings. There are 
// various applications of this data structure, such as autocomplete and 
// spellchecker.

// Implement the Trie class:
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie 
// (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously 
// inserted string word that has the prefix prefix, and false otherwise.

// Example 1:
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
 
// Constraints:
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search,
//  and startsWith.

class Trie {
    bool isEnding = false;
    unordered_map<char,Trie*> um = {};
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    
    void insert(string word) {
        Trie* node = this;
        int wordLength = word.length();
        int i=0;
        while(i < wordLength){
            if(node->um.count(word[i])){
                node = node->um[word[i]];
            }else{
                node->um[word[i]] = new Trie();
                node = node->um[word[i]]; 
            }
            i++;
        }
        node->isEnding = true;
        return ;
    }
    
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        int i=0;
        int wordLength = word.length();
        while(i < wordLength){
            if(!node->um.count(word[i])){ return false; }
            node = node->um[word[i]];
            i++;
        }
        if(node->isEnding == true){
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        int i=0;
        int wordLength = prefix.length();
        while(i < wordLength){
            if(!node->um.count(prefix[i])){ return false; }
            node = node->um[prefix[i]];
            i++;
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */