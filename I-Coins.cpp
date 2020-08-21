#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

double moreHeadThanTail(double * p, int n){
    if(n == 1){
        double  answer = p[0];
        return answer;
    }

    if(n == 2){
        double answer = p[0] * p[1];
        return answer;
    }

    if(n == 3){
        double answer = 0;
        double first = p[0] * p[1] * p[2];
        double second = (1 - p[0]) * p[1] * p[2];
        double third = p[0] * (1 - p[1]) * p[2];
        double fourth = p[0] * p[1] * (1 - p[2]);
        return (first + second + third + fourth);
    }

    double ans = moreHeadThanTail(p+1 , n- 1);
    

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
    cout<<moreHeadThanTail(p,n)<<endl;
    return 0;
}