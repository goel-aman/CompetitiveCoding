#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

unordered_map<string,double> um;

double dp[301][301][301];

double sushii(int* a,int n,int d1,int d2,int d3){
    int count = d1 + d2 + d3;

    if(count == 0){
        return 0;
    }
    if(dp[d1][d2][d3] >= 0){
        return dp[d1][d2][d3];
    }

    double prob = (double) n / count;
    double avg = 0;
    
    if(d1 != 0){
        double x_one = sushii(a,n,d1 - 1,d2,d3);
        avg += d1 * x_one;
    }
    if(d2 != 0){
        double x_two = sushii(a,n,d1 + 1,d2 - 1,d3);
        avg += d2 * x_two;
    }
    if(d3 != 0){
        double x_three = sushii(a,n,d1,d2 + 1,d3 - 1);
        avg += d3 * x_three;
    }
    // cout<<avg<<endl;
    avg = (double) avg / count;
    avg = avg + prob;
    dp[d1][d2][d3] = avg; 
    return avg;
}


double sushi(int * a,int n){
    int count = 0;
    // int null_count = 0;
    string stat;
    for(int i=0;i<n;i++){
        if(a[i] != 0){
            count++;
        }
        stat.push_back(a[i]);
    }

    if(um.count(stat) > 0){
        return um[stat];
    }
    // cout<<"count "<<count<<endl;
    if(count == 0){
        return 0;
    }

    double prob = (double) n /count;
    // cout<<"prob"<<prob<<endl;
    double avg = 0;
    for(int i=0;i<n;i++){
        int b[n];
        string tempp;
        for(int i=0;i<n;i++){
            b[i] = a[i];
            tempp.push_back(b[i]);
        }
        if(b[i] > 0)
        {
            b[i] -= 1;
            tempp[i] =  tempp[i] - 1;
            double temp= sushi(b,n);
            // sort(tempp.begin(),tempp.end());
            // do{
            //     um[tempp] = temp;
            // }while(next_permutation(tempp.begin(),tempp.end()));
            um[tempp] = temp;
            // cout<<"temp "<<temp<<endl;
            avg += temp;
        }
    }
    avg = (double) avg / count;
    avg = avg + prob;
    // cout<<avg<<endl;
    sort(stat.begin(),stat.end());
    do{
        um[stat] = avg;
    }while(next_permutation(stat.begin(),stat.end()));
    return avg;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) { cin>>a[i]; }
    // printDoublePrecision(sushi(a,n),14);
    // cout<<endl;
    int d0 = 0,d1 = 0,d2 = 0,d3 = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            d1++;
        }
        if(a[i] == 2)
        {
            d2++;
        }
        if(a[i] == 3){
            d3++;
        }
    }
    memset(dp,-1,sizeof(dp));
    printDoublePrecision(sushii(a,n,d1,d2,d3),14);
    cout<<endl;
    return 0;
}