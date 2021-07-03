#include<bits/stdc++.h>
using namespace std;

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


class Solution {
public:

    bool isNumber(char c){
        if(c == '-' || isdigit(c)){
            return true;
        }
        return false;
    }


    NestedInteger deserialize(string s) {
        stack<NestedInteger> st;
        for(auto it = s.begin(); it != s.end();){
            char c = (*it);
            if(isNumber(c)){
                auto it2 = find_if_not(it,s.end(),isNumber);
                int val = stoi(string(it,it2));
                st.top().add(NestedInteger(val));
                it = it2;
            }else{
                if(c == '['){
                    st.push(NestedInteger());
                }
                else if(c == ']'){
                    NestedInteger li = st.top();
                    st.pop();
                    st.top().add(li);
                }
                it++;
            }
        }
        NestedInteger result = st.top().getList().front();
        return result;
    }
};