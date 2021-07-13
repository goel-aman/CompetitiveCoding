#include<bits/stdc++.h>
using namespace std;

// 468. Validate IP Address
// Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" 
// if IP is a valid IPv6 address or "Neither" if IP is not a correct IP
//  of any type.

// A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255
//  and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0"
//  are valid IPv4 addresses but "192.168.01.1", while "192.168.1.00" and 
// "192.168@1.1" are invalid IPv4 addresses.

// A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

// 1 <= xi.length <= 4
// xi is a hexadecimal string which may contain digits, lower-case English 
// letter ('a' to 'f') and upper-case English letters ('A' to 'F').
// Leading zeros are allowed in xi.
// For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and 
// "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while 
// "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334"
//  are invalid IPv6 addresses.

// Example 1:
// Input: IP = "172.16.254.1"
// Output: "IPv4"
// Explanation: This is a valid IPv4 address, return "IPv4".

// Example 2:
// Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
// Output: "IPv6"
// Explanation: This is a valid IPv6 address, return "IPv6".

// Example 3:
// Input: IP = "256.256.256.256"
// Output: "Neither"
// Explanation: This is neither a IPv4 address nor a IPv6 address.

// Example 4:
// Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:"
// Output: "Neither"

// Example 5:
// Input: IP = "1e1.4.5.6"
// Output: "Neither"
 
// Constraints:
// IP consists only of English letters, digits and the 
// characters '.' and ':'.

class Solution {
public:
    string validIPAddress(string IP) {
        int ipLength = IP.length();
        bool isIpv4Suspect = false;
        bool isIpv6Suspect = false;
        int countDot = 0;
        for(int i=0;i<ipLength;i++){
            if(IP[i] == '.'){
                isIpv4Suspect = true;
                countDot++;
            }

            if(IP[i] == ':'){
                isIpv6Suspect = true;
            }
        }
        
        if(countDot != 3 && countDot != 0){
            return "Neither";
        }

        if((isIpv4Suspect == false && isIpv6Suspect == false) || (isIpv4Suspect == true && isIpv6Suspect == true)){
            return "Neither";
        }

        if(isIpv4Suspect){
            bool isDigitAndDot = true;
            for(int i=0;i<ipLength;i++){
                if(isdigit(IP[i]) || IP[i] == '.' ){
                    continue;
                }else{
                    isDigitAndDot = false;
                    return "Neither";
                }
            }

            vector<string> tokens;
            string intermediate;
            stringstream check1(IP);
            while(getline(check1,intermediate,'.')){
                tokens.push_back(intermediate);
            }
            if(tokens.size() != 4){
                return "Neither";
            }
            for(int i=0;i<4;i++){
                if( !(tokens[i].length() >=1 && tokens[i].length() <=3) ){
                    return "Neither";
                }
                if(tokens[i].length() == 0){
                    return "Neither";
                }
                if(tokens[i].length() > 1){
                    if(tokens[i][0] == '0'){
                        return "Neither";
                    }
                }
            }

            for(int i=0;i<4;i++){
                int value = stoi(tokens[i]);
                if( !(value <= 255 && value >= 0) ){
                    return "Neither";
                }
            }
            return "IPv4";
        }

        if(isIpv6Suspect){
            stringstream check1(IP);
            string intermediate;
            vector<string> tokens;
            int value = 0;
            for(int i=0;i<IP.length();i++){
                if(IP[i] == ':'){
                    value++;
                }
            }
            while(getline(check1,intermediate,':')){
                // value++;
                tokens.push_back(intermediate);
            }
            
            // cout<<"hello"<<endl;
            // cout<<"value is : "<<value<<endl;
            if(value != 7){
                return "Neither";
            }
            // cout<<"hello"<<endl;
            int tokensLength = tokens.size();
            cout<<"tokens Size is ;"<<tokensLength<<endl;
            if(tokensLength != 8){
                return "Neither";
            }
            
            for(int i=0;i<8;i++){
                if(!(tokens[i].length() >= 1 && tokens[i].length() <= 4)){
                    return "Neither";
                }

                for(int j=0;j<tokens[i].length();j++){
                    if( !( (tokens[i][j] >= 'a' && tokens[i][j] <= 'f') || (tokens[i][j] >= 'A' && tokens[i][j] <= 'F') || isdigit(tokens[i][j]) ) ){
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};