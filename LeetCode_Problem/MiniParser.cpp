#include<bits/stdc++.h>
using namespace std;

// /**
//  * // This is the interface that allows for creating nested lists.
//  * // You should not implement it, or speculate about its implementation
  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
//  */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger output;
        int sLength = s.length();
        if(sLength == 0){
            return output;
        }

        if(s[0] == '['){
            return deserialize(s.substr(1,sLength - 2));
        }

        stringstream check1(s);
        string intermediate;
        vector<string> tokens;
        while(getline(check1,intermediate,',')){
            tokens.push_back(intermediate);
        }

        for(int i=0;i<tokens.size();i++){
            if(tokens[i][0] == '['){
                output.add(deserialize(tokens[i]));
                continue;
            }
            
            if(tokens[i][0] == '-'){
                int value = stoi(tokens[i].substr(1));
                output.add(-1*value);
            }
        }
        return output;
    }
};