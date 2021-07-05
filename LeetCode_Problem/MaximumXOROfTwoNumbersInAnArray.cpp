#include<bits/stdc++.h>
using namespace std;

// 421. Maximum XOR of Two Numbers in an Array
// Given an integer array nums, return the maximum 
// result of nums[i] XOR nums[j], where 0 <= i <= j < n.

// Example 1:
// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.

// Example 2:
// Input: nums = [0]
// Output: 0

// Example 3:
// Input: nums = [2,4]
// Output: 6

// Example 4:
// Input: nums = [8,10,2]
// Output: 10

// Example 5:
// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127
 
// Constraints:
// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 231 - 1

class TrieNode{
    public:
    TrieNode* left;
    TrieNode* right;
};


// left hand side zero
// right hand side one

void insert(TrieNode* head,int number){
    TrieNode* curr = head;
    for(int i=31;i>=0;i--){
        int lastbit = (number>>i)&1;
        if(lastbit == 0){
            if(!curr->left){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }else{
            if(!curr->right){
               curr->right = new TrieNode(); 
            }           
            curr = curr->right;
        }
    }
    return ;
}


// left hand side zero
// right hand side one

int MaxXor(TrieNode* head,vector<int>& nums){
    int numsLength = nums.size();
    int maxXor = 0;
    for(int i=0;i<numsLength;i++){
        int number = nums[i];
        
        int val = 0;
        TrieNode* curr = head;
        for(int j = 31;j>=0;j--){
            
            int lastDigit = (number>>j)&1;
            if(lastDigit == 0){
                if(curr->right){
                    val += pow(2,j);
                    curr = curr->right;
                    continue;
                }
                curr = curr->left;
            }
            else{
                if(curr->left){
                    val += pow(2,j);
                    curr = curr->left;
                    continue;
                }
                curr = curr->right;
            }
        }
        maxXor = max(maxXor,val);
    }
    return maxXor;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int numsLength = nums.size();
        TrieNode* curr = new TrieNode();
        for(int i=0;i<numsLength;i++){
            insert(curr,nums[i]);
        }

        int ans = MaxXor(curr,nums);
        return ans;
    }
};