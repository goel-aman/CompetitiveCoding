#include<bits/stdc++.h>
using namespace std;

// 535. Encode and Decode TinyURL
// Note: This is a companion problem to the 
// System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you
//  enter a URL such as 
// https://leetcode.com/problems/design-tinyurl and
// it returns a short URL such as http://tinyurl.com/4e9iAk.

//  Design a class to encode a URL and decode a tiny URL.
// There is no restriction on how your encode/decode 
// algorithm should work. You just need to ensure that a 
// URL can be encoded to a tiny URL and the tiny URL can
//  be decoded to the original URL.

// Implement the Solution class:
// Solution() Initializes the object of the system.
// String encode(String longUrl) Returns a tiny URL for
//  the given longUrl.
// String decode(String shortUrl) Returns the original 
// long URL for the given shortUrl. It is guaranteed that 
// the given shortUrl was encoded by the same object.
 
// Example 1:
// Input: url = "https://leetcode.com/problems/design-tinyurl"
// Output: "https://leetcode.com/problems/design-tinyurl"

// Explanation:
// Solution obj = new Solution();
// string tiny = obj.encode(url); // returns the encoded tiny url.
// string ans = obj.decode(tiny); // returns the original
//  url after deconding it.
 
// Constraints:
// 1 <= url.length <= 104
// url is guranteed to be a valid URL.

class Solution {
    unordered_map<string,int> um;
    unordered_map<int,string> rev;
    int count = 0;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        vector<string> tokens;
        stringstream check(longUrl);
        string intermediate;
        while(getline(check,intermediate,'/')){
            tokens.push_back(intermediate);
        }

        string ret = "";
        for(auto var : tokens){
            if(!um.count(var)){
                um[var] = count;
                rev[count] = var;
                count++;
            }
            ret += to_string(um[var]) + "/";
        }
        if(longUrl[longUrl.length() - 1] == '/'){
            ret += "/";
        }
        // ret = ret.substr(0,ret.length() - 1);
        return ret;
    }


    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        vector<string> tokens;
        stringstream check(shortUrl);
        string intermediate;
        while(getline(check,intermediate,'/')){
            tokens.push_back(intermediate);
        }
        string ret = "";
        for(auto var : tokens){
            if(var == ""){
                ret += "/";
                continue;
            }
            ret += rev[(stoi(var))] + "/";
        }
        return ret.substr(0,ret.length() - 1);
    }
};
