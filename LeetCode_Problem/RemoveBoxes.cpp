// 546. Remove Boxes

// Given several boxes with different colors represented by different positive numbers.
// You may experience several rounds to remove boxes until there is no box left. Each 
// time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1)
// , remove them and get k*k points.
// Find the maximum points you can get.

// Example 1:
// Input: boxes = [1,3,2,2,2,3,4,3,1]
// Output: 23
// Explanation:
// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
// ----> [1, 1] (3*3=9 points) 
// ----> [] (2*2=4 points)
 
// Constraints:

// 1 <= boxes.length <= 100
// 1 <= boxes[i] <= 100

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getAnswer(string str){
        int length = str.length();
        if(length == 0){
            return 0;
        }

        if(length == 1){
            return 1;
        }
        int final_ans = INT_MIN;
        int start = 0;
        char prev = str[0];
        int count = 1;
        for(int i=1;i<length;i++){
            if(str[i] == prev){
                count++;
                continue;
            }
            else{
                int ans = 0;
                ans += (count * count);
                if(start == 0){
                    ans += getAnswer(str.substr(i));
                    final_ans = max(final_ans,ans);
                }else{
                    ans += getAnswer(str.substr(0,start - 0)) + getAnswer(str.substr(i));
                    final_ans = max(final_ans,ans);
                }
                start = i;
                prev = str[i];
                count = 1;
            }
        }
        if(count == 1){
            int ans = 1;
            ans += getAnswer(str.substr(0,length - 1));
            final_ans = max(final_ans,ans);
        }

        if(count > 1){
            int ans = (count * count);
            ans += getAnswer(str.substr(0,length - count));
            final_ans = max(final_ans,ans);
        }
        return final_ans;
    }

    int removeBoxes(vector<int>& boxes) {
        string a;
        for(auto m : boxes){
            a.push_back(m);
        }

        return getAnswer(a);
    }
};
