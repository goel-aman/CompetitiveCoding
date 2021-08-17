#include<bits/stdc++.h>
using namespace std;

int helper(int n,int current,int k){
    if(n == 0){
        return 1;
    }
    if(n < current){
        return 0;
    }

    if(current == k){
        if(n%k == 0){
            return 1;
        }
        return 0;
    }

    int ans = 0;
    int maxTime = n / current;
    for(int i=0;i<=maxTime;i++){
        ans += helper(n - (i * current),current + 1,k);
    }
    return ans;
}

int solve(int k,int n){
    return helper(n,1,k);
}

int main(){
    cout<<solve(2,8);
}