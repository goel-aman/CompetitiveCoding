#include<bits/stdc++.h>
using namespace std;

// 658. Find K Closest Elements

// Given a sorted integer array arr, two integers k and x, return the k closest
//  integers to x in the array. The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:
// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 
// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]
 
// Constraints:
// 1 <= k <= arr.length
// 1 <= arr.length <= 104
// arr is sorted in ascending order.
// -104 <= arr[i], x <= 104

class Solution {
public:

    int findSlightlyGreaterOrEqual(vector<int>& arr,int k,int x){
        int arrLength = arr.size();
        int start = 0;
        int end = arrLength - 1;
        int answer = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(x == arr[mid]){
                return mid;
            }

            if(arr[mid] > x){
                answer = mid;
                end = mid - 1;
                continue;
            }
            
            if(arr[mid] < x){
                start = mid + 1;
                continue;
            }
        }
        if(answer == -1){
            return arrLength - 1;
        }
        return answer;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int arrLength = arr.size();
        int index = findSlightlyGreaterOrEqual(arr,k,x);
        cout<<"index value is : "<<index<<endl;
        vector<int> ans;
        if(index == 0){
            for(int i=0;i<k;i++){
                ans.push_back(arr[i]);
               
            }
             return ans;
        }

        if(index == arrLength - 1 && arrLength != 2){
            for(int i=arrLength - k;i<arrLength;i++){
                ans.push_back(arr[i]);
                
            }
            return ans;
        }
        int tempk = k;
        int first = index - 1;
        int second = index;

        while(tempk > 0){
            int firstNumDifference = INT_MAX,secondNumDifference = INT_MAX;
            if(first < arrLength && first >=0){
                firstNumDifference = abs(x - arr[first]);
            }

            if(second < arrLength && second >= 0){
                secondNumDifference = abs(x - arr[second]);
            }

            if(firstNumDifference <= secondNumDifference){
                ans.push_back(arr[first]);
                first--;
                tempk--;
                continue;
            }

            if(secondNumDifference < firstNumDifference){
                ans.push_back(arr[second]);
                second++;
                tempk--;
                continue;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};