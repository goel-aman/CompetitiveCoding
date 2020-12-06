#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int length = nums.size();
        int **  matrix = new int*[length + 2];
        for(int i=0;i<=length + 1;i++){
            matrix[i] = new int[length + 2];
            for(int j=0;j<=length + 1;j++){
                matrix[i][j] = 0;
            }
        }

        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // cout<<"Printing the vector "<<endl;
        // for(auto pr : nums)
        // {
        //     cout<<pr<<" ";
        // }
        // cout<<endl;

        for(int m=1;m<=length;m++){
            int j = m;
            int i = 1;
            while(i <= length && j<= length){
                int maxx = 0;
                for(int k = i;k<=j;k++){
                    maxx = max(maxx,matrix[i][k - 1] + matrix[k+1][j] + nums[k] * nums[k - 1] * nums[k + 1]);
                }
                matrix[i][j] = maxx;
                i++;
                j++;
            }
        } 
        for(int i=0;i<=length;i++){
            for(int j=0;j<=length;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return matrix[1][length];
    }
};


int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> input;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        input.push_back(elem);
    }
    s.maxCoins(input);
}