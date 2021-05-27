#include<bits/stdc++.h>
using namespace std;

// 1291. Sequential Digits

// An integer has sequential digits if and only if each digit in 
// the number is one more than the previous digit.
// Return a sorted list of all the integers in the 
// range [low, high] inclusive that have sequential digits.

// Example 1:
// Input: low = 100, high = 300
// Output: [123,234]

// Example 2:
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 
// Constraints:
// 10 <= low <= high <= 10^9

class Solution {
public:
    void Digits(int low,int high,int length,int prevNumber,vector<int>& res){
        if(prevNumber == -1){
            for(int i=1;i<= (10 - length);i++){
                Digits(low,high,length - 1,i,res);
            }
            return;
        }

        if(length == 0){
            if(prevNumber >= low && prevNumber <= high){
                res.push_back(prevNumber);
            }
            return;
        }

        int lastDigit = prevNumber % 10;
        if(lastDigit + 1 < 10){
            int temp = (prevNumber * 10) + lastDigit + 1;
            Digits(low,high,length - 1, temp,res);
        }
        return ;
    }
    
    int findLength(int number){
        int length = 0;
        while(number != 0){
            number = number / 10;
            length++;
        }
        return length;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int lowLength = findLength(low);
        int highLength = findLength(high);

        for(int i=lowLength;i<=highLength;i++){
            Digits(low,high,i,-1,res);
        }
        return res;
    }
};