#include<bits/stdc++.h>
using namespace std;

// 1054. Distant Barcodes

// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
// Rearrange the barcodes so that no two adjacent barcodes are equal.
//  You may return any answer, and it is guaranteed an answer exists.

// Example 1:
// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]

// Example 2:
// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
 
// Constraints:
// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000

class element{
    public:
    int freq;
    int element;
};
#include<bits/stdc++.h>
using namespace std;

// 1054. Distant Barcodes

// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
// Rearrange the barcodes so that no two adjacent barcodes are equal.
//  You may return any answer, and it is guaranteed an answer exists.

// Example 1:
// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]

// Example 2:
// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
 
// Constraints:
// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int barcodeLength = barcodes.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> um;
        for(int i=0;i<barcodeLength;i++){
            um[barcodes[i]]++;
        }
        for(auto elem : um){
            pq.push({elem.second,elem.first});
        }

        int start = 0;
        vector<int> ans;
        int prev = -1;
        while(pq.size() > 1){
            pair<int,int> first = pq.top();
            pq.pop();
            pair<int,int> second = pq.top();
            pq.pop();
            
            int firstElement = first.second;
            int secondElement = second.second;
            if(firstElement != prev){
                ans.push_back(firstElement);
                ans.push_back(secondElement);
                prev = secondElement;
            }else{
                ans.push_back(secondElement);
                ans.push_back(firstElement);
                prev = firstElement;
            }


            if( (first.first - 1) != 0){
                pq.push({first.first - 1,first.second});
            }

            if((second.first - 1) != 0){
                pq.push({second.first - 1,second.second});
            }
        }
        if(!pq.empty()){
            pair<int,int> front = pq.top();
            ans.push_back(front.second);
        }
        return ans;
    }
};