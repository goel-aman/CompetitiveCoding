// 131. Palindrome Partitioning

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,bool> um;
    unordered_map<string,vector<vector<string>>> umm;
public:

    bool isPalindrome(string s){
        int slength = s.length();
        
        if(um.count(s) > 0){
            return um[s];
       }
       if(slength == 0){
            return um[s]=true;
        }
        
        
        if(slength == 1){
            return um[s]=true;
        }
        
        

        if(s[0] == s[slength - 1]){
            return um[s]=isPalindrome(s.substr(1,slength - 2));
        }
        return um[s]=false;
    }

    vector<vector<string>> partition(string s) {
        if(umm.count(s) > 0){
            return umm[s];
        }
        cout<<"Input string is : "<<s<<endl;
        vector<vector<string>> ans;
        int slength = s.length();
        if(slength == 1){
            ans.push_back({s});
            return umm[s] = ans;
        }

        

        for(int i=1;i<=slength;i++){
            if(isPalindrome(s.substr(0,i))){
                vector<vector<string>> an = partition(s.substr(i));
                if(an.size() == 0){
                    ans.push_back({s.substr(0,i)});
                    // ans.push_back(an);
                    continue;
                }
                for(auto vec : an){
                    vec.insert(vec.begin(),s.substr(0,i));
                    ans.push_back(vec);
                }
            }
        }
        return umm[s] = ans;
    }
};
