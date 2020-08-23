#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x
const int k = 3000;


double moreHeadThanTail(double * p, int i,int &n,int head_count,double dp[][3000]){
    if(i == n){
        if(head_count <= 0){
            return 1;
        }
        
        return 0;
    }

    if(head_count <= 0){
        return 1;
    }
    if(dp[i][head_count] >= 0){
        return dp[i][head_count];
    }


    double x = p[i] *moreHeadThanTail(p,i+1,n,head_count - 1,dp) + (1 - p[i]) * moreHeadThanTail(p,i+1,n,head_count,dp);
    return dp[i][head_count] = x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    double p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int head_count = (n / 2) + 1;
    double dp[n+1][3000];
    memset(dp,-1,sizeof(dp));
    printDoublePrecision( moreHeadThanTail(p,0,n,head_count,dp),10);
    cout<<endl;
    // cout<< fixed << setprecision(10) << moreHeadThanTail(p,0,n,head_count,dp)<<endl;
    return 0;
}