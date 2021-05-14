#include<bits/stdc++.h>
using namespace std;

// 1286. Iterator for Combination

// Design the CombinationIterator class:
// CombinationIterator(string characters, int combinationLength) Initializes the object
// with a string characters of sorted distinct lowercase English letters and a 
// number combinationLength as arguments.
// next() Returns the next combination of length combinationLength
//  in lexicographical order.
// hasNext() Returns true if and only if there exists a next combination.
 
// Example 1:
// Input
// ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [["abc", 2], [], [], [], [], [], []]
// Output
// [null, "ab", true, "ac", true, "bc", false]

// Explanation
// CombinationIterator itr = new CombinationIterator("abc", 2);
// itr.next();    // return "ab"
// itr.hasNext(); // return True
// itr.next();    // return "ac"
// itr.hasNext(); // return True
// itr.next();    // return "bc"
// itr.hasNext(); // return False
 
// Constraints:
// 1 <= combinationLength <= characters.length <= 15
// All the characters of characters are unique.
// At most 104 calls will be made to next and hasNext.
// It's guaranteed that all calls of the function next are valid.

class CombinationIterator {
    vector<string> ans;
    int pointer;
    int sLength;
    int ansLength;

public:
    CombinationIterator(string characters, int combinationLength) {
        string res = "";
        sLength = characters.length();
        func(characters,combinationLength,0,res);
        ansLength = ans.size();
        pointer = 0;
    }

    void func(string s,int stringLength,int position,string &res){
        if(stringLength == 0){
            ans.push_back(res);
            return;
        }


        if(position >= sLength ){
            return ;
        }

        res.push_back(s[position]);
        func(s,stringLength - 1,position + 1,res);
        res.pop_back();
        func(s,stringLength,position + 1,res);
        return ;
    }
    
    string next() {
        string ret = ans[pointer];
        pointer++;
        return ret;
    }
    
    bool hasNext() {
        if(pointer < ansLength){
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */