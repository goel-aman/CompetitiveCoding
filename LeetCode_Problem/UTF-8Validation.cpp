#include<bits/stdc++.h>
using namespace std;

// 393. UTF-8 Validation
// Given an integer array data representing the 
// data, return whether it is a valid UTF-8 encoding.

// A character in UTF8 can be from 1 to 4 bytes 
// long, subjected to the following rules:

// For a 1-byte character, the first bit is a 0,
//  followed by its Unicode code.
// For an n-bytes character, the first n bits are
//  all one's, the n + 1 bit is 0, followed by
//  n - 1 bytes with the most significant 2 bits
//  being 10.
// This is how the UTF-8 encoding would work:

//    Char. number range  |        UTF-8 octet sequence
//       (hexadecimal)    |              (binary)
//    --------------------+---------------------------------------------
//    0000 0000-0000 007F | 0xxxxxxx
//    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// Note: The input is an array of integers. Only the least
//  significant 8 bits of each integer is used to store the
//  data. This means each integer represents only 1 byte 
// of data.

// Example 1:
// Input: data = [197,130,1]
// Output: true
// Explanation: data represents the octet 
// sequence: 11000101 10000010 00000001.
// It is a valid utf-8 encoding for a 2-bytes 
// character followed by a 1-byte character.

// Example 2:
// Input: data = [235,140,4]
// Output: false
// Explanation: data represented the octet 
// sequence: 11101011 10001100 00000100.
// The first 3 bits are all one's and the 4th
//  bit is 0 means it is a 3-bytes character.
// The next byte is a continuation byte which
//  starts with 10 and that's correct.
// But the second continuation byte does not
//  start with 10, so it is invalid.
 
// Constraints:
// 1 <= data.length <= 2 * 104
// 0 <= data[i] <= 255

class Solution {
public:
    string convert(int data)
    {
        string ret = "";
        int start = 7;
        while(start >= 0){
            int value = (1<<start);
            int lastDigit = (value&data);
            if(lastDigit == 0){
                ret.push_back('0');
            }else{
                ret.push_back('1');
            }
            // ret.push_back(lastDigit + '0');
            start--;
        }
        // reverse(ret.begin(),ret.end());
        return ret;
    }

    bool validUtf8(vector<int>& data) {
        vector<string> dat;
        int dataLength = data.size();
        for(int i=0;i<dataLength;i++){
            dat.push_back(convert(data[i]));
            cout<<dat[i]<<" ";
        }
        cout<<endl;

        bool ans = true;

        int next = -1;
        int count = 0;
        for(int i=0;i<dataLength;i++){
            string s = dat[i];
            int type = -1;
            if(s.substr(0,1) == "0"){
                type = 1;
            }
            if(s.substr(0,2) == "10"){
                type = 5;
            }

            if(s.substr(0,3) == "110"){
                type = 2;
            }

            if(s.substr(0,4) == "1110"){
                type = 3;
            }

            if(s.substr(0,5) == "11110"){
                type = 4;
            }

            if(count == 0){
                if(type == 5){
                    ans = false;
                    return ans;
                }

                if(type == 1){
                    continue;
                }

                count = type - 1;
                next = 5;
                continue;
            }

            if(count != 0){
                if(type != next){
                    ans = false;
                    return ans;
                }

                count = count - 1;
                if(count == 0){
                    next = -1;
                }
            }
        }
        if(count != 0){
            return false;
        }
        return true;
    }
};