#include <bits/stdc++.h>
using namespace std;

// 870. Advantage Shuffle

// Given two arrays A and B of equal size, the advantage of A with respect to
//  B is the number of indices i for which A[i] > B[i].
// Return any permutation of A that maximizes its advantage with respect to B.

// Example 1:
// Input: A = [2,7,11,15], B = [1,10,4,11]
// Output: [2,11,7,15]

// Example 2:
// Input: A = [12,24,8,32], B = [13,25,32,11]
// Output: [24,32,8,12]

// Note:
// 1 <= A.length = B.length <= 10000
// 0 <= A[i] <= 10^9
// 0 <= B[i] <= 10^9

class elem{
public:
    int index;
    int value;
};

bool compare(elem &a,elem &b){
    if(a.value <= b.value){
        return true;
    }
    return false;
}

class Solution{
public:

    vector<int> advantageCount(vector<int> &A, vector<int> &B){
        int length = A.size();
        elem first[length];
        elem second[length];
        
        for(int i=0;i<length;i++){
            first[i].index = i;
            first[i].value = A[i];

            second[i].index = i;
            second[i].value = B[i];
        }

        sort(first , first + length,compare);
        sort(second,second + length,compare);

        vector<int> answer(length);
        // aim is to arrange A
        int start = 0; int end = length - 1;
        for(int i=length-1;i>=0;i--){
            int val = second[i].value;
            int index = second[i].index;
            if(first[end].value > val){
                answer[index] = first[end].value;
                end--;
            }else{
                answer[index] = first[start].value;
                start++;
            }
        }
        return answer;
    }
};