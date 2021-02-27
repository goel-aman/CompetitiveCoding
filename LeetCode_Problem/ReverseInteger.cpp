#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        long long int value = (long long)((long long)1<<31);
        long long int low = -1 * value;
        long long int high = value - 1;
        int negative = 0;
        if(x < 0){
            negative = 1;
        }
        if(x == low){
            return 0;
        }
        x = -1 * x;
        string number = to_string(x);
        std::reverse(number.begin(),number.end());
        if(stoll(number) > high || stoll(number) < low){
            return 0;
        }
        int i=0;
        int length = number.length();
        while(true){
            if(number[i] == '0'){
                number = number.substr(1);
                length--;
                if(length == 0){
                    break;
                }
            }
            else{
                break;
            }
        }
        if(number.size() == 0){
            return 0;
        }
        
        if(negative){
            return (-1 *stoi(number));
        }
        return stoi(number);
    }
};