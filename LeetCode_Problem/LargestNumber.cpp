#include<bits/stdc++.h>
using namespace std;


// Given a list of non-negative integers nums, arrange them 
// such that they form the largest number.
// Note: The result may be very large, so you need to return
//  a string instead of an integer.
 
// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Example 3:
// Input: nums = [1]
// Output: "1"

// Example 4:
// Input: nums = [10]
// Output: "10"
 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109
bool compare(string &s1,string &s2){
    unsigned long long int one = stoull(s1 + s2);
    unsigned long long int two = stoull(s2 + s1);
    if(one < two){
        return true;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numss;
        int numsLength = nums.size();
        for(int i=0;i<numsLength;i++){
            numss.push_back(to_string(nums[i]));
        }
        sort(numss.begin(),numss.end(),compare);
        
        string ans = "";
        int count = 0;
        for(int i=numsLength - 1;i>=0;i--){
            if(numss[i] == "0"){
                count++;
            }
            ans += numss[i];
        }
        
        if(count == numsLength){
            return "0";
        }
        return ans;
    }
};

