#include<bits/stdc++.h>
using namespace std;

// 402. Remove K Digits
// Given string num representing a non-negative 
// integer num, and 
// an integer k, return the smallest possible integer after 
// removing k digits from num.

// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the 
// new number 1219 which is the smallest.

// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and 
// the number is 200. Note 
// that the output must not contain leading zeroes.

// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is 
// left with nothing which is 0.
 
// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros
//  except for the zero itself.


class Solution {
public:
    string removeKdigits(string num, int k) {
        bool visit = false;
        int numLength = num.length();
        int lengthRequired = numLength - k;
        if(lengthRequired == 0){
            return "0";
        }
        stack<char> st;
        string ans = "";
        int i = 0;
        for(;i<numLength;i++){
           
            int leftOut = numLength - i;
            
            if(st.size() + leftOut == lengthRequired){
                visit = true;
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                for(int j= i;j<numLength;j++){
                    ans.push_back(num[j]);
                }
                break;
            }
            int iteration = st.size() + (numLength - i) - lengthRequired;
            while(!st.empty() && st.top() - '0' > (num[i] - '0') && iteration > 0){
                st.pop();
                iteration--;
            }    
            
            st.push(num[i]);
        }
        // cout<<"answer is : "<<ans<<endl;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // cout<<"answer is : "<<ans<<endl;
        if(visit == false){
            reverse(ans.begin(),ans.end());
            ans = ans.substr(0,lengthRequired);
        }
        
        int index = -1;
        for(int w = 0;w<ans.length();w++){
            if(ans[w] == '0'){
                index = w;
            }else{
                break;
            }
        }
        
        if(index != -1){
            ans = ans.substr(index + 1);
        }
        
        if(ans == ""){
            return "0";
        }
    
        return ans;
    }

};