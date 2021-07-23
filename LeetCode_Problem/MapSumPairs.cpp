#include<bits/stdc++.h>
using namespace std;

// 677. Map Sum Pairs
// Implement the MapSum class:
// MapSum() Initializes the MapSum object.
// void insert(String key, int val) Inserts the 
// key-val pair into the map. If the key already 
// existed, the original key-value pair will be 
// overridden to the new one.
// int sum(string prefix) Returns the sum of all 
// the pairs' value whose key starts with the prefix.
 
// Example 1:
// Input
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// Output
// [null, null, 3, null, 5]

// Explanation
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);  
// mapSum.sum("ap");           // return 3 (apple = 3)
// mapSum.insert("app", 2);    
// mapSum.sum("ap");           
// return 5 (apple + app = 3 + 2 = 5)
 
// Constraints:
// 1 <= key.length, prefix.length <= 50
// key and prefix consist of only lowercase English letters.
// 1 <= val <= 1000
// At most 50 calls will be made to insert and sum.

class TrieNode{
    public:
    unordered_map<char,TrieNode*> um;
    int sum = 0;
};

class MapSum {
    unordered_map<string,int> extra;
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();       
    }

    void insertt(string key,int val,TrieNode* root,int subtract){
        int keyLength = key.length();
        if(keyLength == 0){
            return ;
        }

        if(root->um.count(key[0])){
            root->um[key[0]]->sum += val;
            root->um[key[0]]->sum -= subtract;
            insertt(key.substr(1),val,root->um[key[0]],subtract);
            return ;
        }else{
            root->um[key[0]] = new TrieNode();
            root->um[key[0]]->sum += val;
            root->um[key[0]]->sum -= subtract;
            insertt(key.substr(1),val,root->um[key[0]],subtract);
        }
        return ;
    }
    
    void insert(string key, int val) {
        int keyLength = key.length();
        if(keyLength == 0){
            return ;
        }
        if(extra.count(key) > 0){
            insertt(key,val,root,extra[key]);
            extra[key] = val;
            return ;
        }   
        extra[key] = val;
        insertt(key,val,root,0);
        return ;
    }
    
    int sum(string prefix) {
        int prefixLength = prefix.size();
        TrieNode* tempRoot = root;
        for(int i=0;i<prefixLength;i++){
            char val = prefix[i];
            if(tempRoot->um.count(val) > 0){
                tempRoot = tempRoot->um[val];
                continue;
            }else{
                return 0;
            }
        }

        return tempRoot->sum;
    }
};
