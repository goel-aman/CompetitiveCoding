#include<bits/stdc++.h>
using namespace std;

// 275. H-Index II
// Given an array of integers citations where citations[i] is the number of
//  citations a researcher received for their ith paper and citations is sorted 
// in an ascending order, return compute the researcher's h-index.
// According to the definition of h-index on Wikipedia: A scientist has an index 
// h if h of their n papers have at least h citations each, and the other n − h papers
//  have no more than h citations each.
// If there are several possible values for h, the maximum one is taken as the h-index.

// Example 1:
// Input: citations = [0,1,3,5,6]
// Output: 3
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them 
// had received 0, 1, 3, 5, 6 citations respectively.
// Since the researcher has 3 papers with at least 3 citations each and the remaining 
// two with no more than 3 citations each, their h-index is 3.

// Example 2:
// Input: citations = [1,2,100]
// Output: 2
 
// Constraints:
// n == citations.length
// 1 <= n <= 105
// 0 <= citations[i] <= 1000
// citations is sorted in ascending order.
 
// Follow up: Could you solve it in logarithmic time complexity?

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int citationsLength = citations.size();
        if(citationsLength == 1){
            if(citations[0] != 0){
                return 1;
            }           
            return 0;
        }
        int start = 1, end = citationsLength;
        int answer = INT_MIN;
        while(start <= end){
            int mid = (start + end) / 2;
            // if(mid == citationsLength){
            //     break;
            // }
            if(citations[citationsLength - mid] >= mid){
                if(citationsLength - mid - 1 >= 0 && citations[citationsLength - mid - 1] <= mid){
                    answer = max(answer,mid);
                    start = mid + 1;
                    continue;
                }
                
                if(citationsLength - mid - 1 < 0){
                    return citationsLength;
                }
            }

            if( !(citations[citationsLength - mid] >= mid)){
                end = mid - 1;
                continue;
            }

            if(!(citations[citationsLength - mid - 1] <= mid)){
                start = mid + 1;
                continue;
            }
        }
        if(answer == INT_MIN){
            return 0;
        }
        return answer;
    }
};