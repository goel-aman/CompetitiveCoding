// 639. Decode Ways II

// A message containing letters from A-Z is being encoded to numbers using the following mapping way:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

// Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

// Also, since the answer may be very large, you should return the output mod 109 + 7.

// Example 1:
// Input: "*"
// Output: 9
// Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
// Example 2:
// Input: "1*"
// Output: 9 + 9 = 18
// Note:
// The length of the input string will fit in range [1, 105].
// The input string will only contain the character '*' and digits '0' - '9'.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1000000007;
public:
    int numDecodings(string s) {
        int length = s.length();
        if(length == 0){
            return 1;
        }
        if(s[0] == '0'){
            return 0;
        }
        
        if(length == 1){
            if(s[0] == '0'){
                return 0;
            }
            if(s[0] == '*'){
                return 9;
            }  
            return 1;
        }
        
        int ans = 0;
        int ans1 = 0;
        int ans2 = 0;
        if(s[0] == '*' && s[1] == '0'){
            return (2 * numDecodings(s.substr(2)))%mod;
        }
        
        if(s[0] == '*'){
            ans1 = (9 * numDecodings(s.substr(1)))%mod;
            if(s[1] == '*'){
                ans2 = (15  * numDecodings(s.substr(2)))%mod;
                return (ans1 + ans2)%mod;
            }else{
                if(s[1] - '0' > 6){
                    ans2 = (1 * numDecodings(s.substr(2)))%mod;
                    return (ans1 + ans2)%mod;
                }else{
                    ans2 =  (2 *  numDecodings(s.substr(2)))%mod;
                    return (ans1 + ans2)%mod;
                }
            }
        }
        
        ans1 =  numDecodings(s.substr(1))%mod;
        if(s[1] == '*'){
            if(length > 2 && s[2] == '0'){
                return (2 * numDecodings(s.substr(3)))%mod;
            }
            if(s[0] == '1'){
                ans2 = (9 * numDecodings(s.substr(2)))%mod;
                return (ans1 + ans2)%mod;
            }
            else if(s[0] == '2'){
                ans2 = (6 * numDecodings(s.substr(2)))%mod;
                return (ans1 + ans2)%mod;
            }else{
                return ans1;
            }
        }else{
            string sub = s.substr(0,2);
            int val = stoi(sub);
            if(val <= 26){
                ans2 = 1 * numDecodings(s.substr(2));
                return (ans1 + ans2)%mod;
            }
        }
        return (ans1 + ans2)%mod;
    }
};

