#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int compute(int n){
        if(n == 1 || n == 0){
            return 0;
        }
        if(n%2 == 0){
            return (n/2) - 1;
        }

        return n/2;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        if(length == 1){
            if(flowerbed[0] == 0){
                if(n <= 1){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(n <= 0){
                    return true;
                }
                return false;
            }
        }
        vector<int> a;
        int ans=0;
        int zerocount = 0;
        int flag = 0;
        for(int i=0;i<length;i++){
            if(flowerbed[i] == 1){
                a.push_back(zerocount);
                // ans += compute(zerocount);
                zerocount = 0;
                // continue;
            }
            else{
                zerocount++;
            }
        }
        
        if(zerocount == length){
            if(zerocount%2 == 0){
                if(n <= (length/2)){
                    return true;
                }
                return false;
            }
            else{
                if(n <= (length / 2) + 1){
                    return true;
                }
                return false;
            }
        }
        
        if(zerocount > 0){
            a.push_back(zerocount);
            // ans += compute(zerocount;
        }
        
        if(flowerbed[0] == 0 && flowerbed[length - 1] == 0){
            int ann = 0;
            int alength = a.size();
            for(int i=1;i<alength - 1;i++){
                ann += compute(a[i]);
            }
            ann += a[0] /  2;
            ann += a[alength - 1] /2; 
            if(n <= ann){
                return true;
            }
            return false;
        }
        
        if(flowerbed[0] == 0){
            int ann = 0;
            int alength = a.size();
            for(int i=1;i<alength;i++){
                ann += compute(a[i]);
            }
            ann += a[0] / 2;
            if(n <= ann){
                return true;
            }
            return false;
        }
        
        if(flowerbed[length - 1] == 0){
            int ann = 0;
            int alength = a.size();
            for(int i=0;i<alength - 1;i++){
                ann += compute(a[i]);
            }
            ann += a[alength - 1] / 2;
            if(n <= ann){
                return true;
            }
            return false;
        }
        
        for(auto ss : a){
            ans += compute(ss);
        }
        
        if(n <= ans){
            return true;
        }
        
        return false;
    }
};