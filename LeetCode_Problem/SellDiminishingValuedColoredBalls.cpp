#include<bits/stdc++.h>
using namespace std;

// 1648. Sell Diminishing-Valued Colored Balls
// You have an inventory of different colored balls, and
//  there is a customer that wants orders balls of any color.
// The customer weirdly values the colored balls. Each colored 
// ball's value is the number of balls of that color you currently
//  have in your inventory. For example, if you own 6 yellow balls,
//  the customer would pay 6 for the first yellow ball. After the 
// transaction, there are only 5 yellow balls left, so the next 
// yellow ball is then valued at 5 (i.e., the value of the balls 
// decreases as you sell more to the customer).

// You are given an integer array, inventory, where inventory[i] represents
//  the number of balls of the ith color that you initially own. You are also
//  given an integer orders, which represents the total number of balls that 
// the customer wants. You can sell the balls in any order.

// Return the maximum total value that you can attain after selling orders 
// colored balls. As the answer may be too large, return it modulo 109 + 7.

// Example 1:
// Input: inventory = [2,5], orders = 4
// Output: 14
// Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
// The maximum total value is 2 + 5 + 4 + 3 = 14.
// Example 2:

// Input: inventory = [3,5], orders = 6
// Output: 19
// Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
// The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
// Example 3:

// Input: inventory = [2,8,4,10,6], orders = 20
// Output: 110
// Example 4:

// Input: inventory = [1000000000], orders = 1000000000
// Output: 21
// Explanation: Sell the 1st color 1000000000 times
//  for a total value of 500000000500000000. 500000000500000000 modulo 109 + 7 = 21.
 
// Constraints:
// 1 <= inventory.length <= 105
// 1 <= inventory[i] <= 109
// 1 <= orders <= min(sum(inventory[i]), 109)


class element{
    public:
    long long int value;
    long long int frequency;
};

class compare{
    public:
    bool operator()(element &first,element &second){
        if(first.value < second.value){
            return true;
        }
        return false;
    }
};

class Solution {
    int mod = 1e9 + 7;
public:
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<element,vector<element>,compare> pq;
        pq.push({0,0});
        unordered_map<long long int,long long int> frequency;
        
        for(auto var : inventory){
            frequency[var]++;
        }
        
        for(auto var : frequency){
            pq.push({var.first,var.second});
        }
        
        long long int sum = 0;
        while(orders > 0){
            element front = pq.top();
            pq.pop();
            element second = pq.top();
            pq.pop();
            int diff = front.value - second.value;
            if(diff * front.frequency <= orders){
                second.frequency += front.frequency;
                orders -= (diff * front.frequency);
                sum = (long long int)sum +  (long long int) front.frequency *(long long int) (((front.value * (front.value + 1))/2) - ((second.value * (second.value + 1))/2)); 
                sum = sum % mod;
                pq.push(second);
                continue;
            }

            if(orders <= front.frequency){
                sum = sum + (front.value * orders);
                orders = 0;
                break; 
            }

            long long int iter = orders / front.frequency;
            element next;
            orders -= iter * front.frequency;
            next.frequency = front.frequency;
            next.value = front.value - iter;
            sum = sum + ((((front.value * (front.value + 1))/2) - ((next.value * (next.value + 1))/2))*next.frequency);
            sum = sum % mod;
            pq.push(second);
            pq.push(next);
        }
        return sum%mod;
    }
};