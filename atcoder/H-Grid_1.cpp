#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    char input[h][w];
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
           cin>>input[i][j];
        }
    }
    ll output[h][w] = {0};
    memset(output,0,sizeof(output));
    ll i=0;
    for(i=0;i<w;i++){
        if(input[0][i] == '.'){
            output[0][i] = 1;
        }
        else{
            break;
        }
    }
    for(;i<w;i++){
        output[0][i] = 0;
    }
    

    ll j = 0;
    for(j = 0;j<h;j++){
        if(input[j][0] == '.'){
            output[j][0] = 1;
        }
        else{
            break;
        }
    }
    for(;j<h;j++){
        output[j][0] = 0;
    }
    for(ll i=1;i<h;i++){
        for(ll j=1;j<w;j++){
            if(input[i][j] == '#'){
                output[i][j] = 0;
                continue;
            }
            else{
                output[i][j] = (output[i][j-1] + output[i-1][j]) % MOD;
            }
        }
    }
    cout<<output[h-1][w-1]<<endl;
    return 0;
}