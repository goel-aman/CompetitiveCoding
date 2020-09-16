#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Sucessfully implemented //////////////////////

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        set<string> s;
        string w;
        for(int i=0;i<arr.size();i++){
            w.push_back(arr[i]);
        }
        for(int i=0;i<=arr.size() - m;i++){
            s.insert(w.substr(i,m));
        }
        
        for(auto u: s){
            string t = u;
            for(int i=0;i<k-1;i++){
                t = t + u;
            }
            for(int i=0;i<=w.size() - t.size() && t.size() <= w.size();i++){
                if(w.substr(i,t.size()) == t){
                    return true;
                }
            }
        }
        return false;
    }
    
};