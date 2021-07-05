#include<bits/stdc++.h>
using namespace std;

// 423. Reconstruct Original Digits from English
// Given a string s containing an out-of-order English 
// representation of digits 0-9, return the digits in
// ascending order.

// Example 1:
// Input: s = "owoztneoer"
// Output: "012"

// Example 2:
// Input: s = "fviefuro"
// Output: "45"
 
// Constraints:
// 1 <= s.length <= 105
// s[i] is one of the characters 
// ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
// s is guaranteed to be valid.

class Solution {
public:
    string originalDigits(string s) {
        vector<char> vec = {'z','g','u','f','v','x','w','t','o','i'};
        vector<int> rep = {0,8,4,5,7,6,2,3,1,9};
        vector<string> vecString = {"zero","eight","four","five","seven","six","two","three","one","nine"};
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++){
            um[s[i]]++;
        }
        
        vector<int> countStore(10,0);
        
        string ret = "";
        int vecSize = vec.size();
        for(int i=0;i<vecSize;i++){
            if(um.count(vec[i]) > 0){
                int times = um[vec[i]];
                countStore[rep[i]] += times;
                string val = vecString[i];
                for(int j = 0;j<val.length();j++){
                    um[val[j]] = um[val[j]] - times;
                }
            }
        }
        
        for(int i=0;i<10;i++){
            if(countStore[i] != 0){
                for(int w=0;w<countStore[i];w++){
                    ret.push_back(i + '0');
                }
            }
        }
        return ret;
    }
};