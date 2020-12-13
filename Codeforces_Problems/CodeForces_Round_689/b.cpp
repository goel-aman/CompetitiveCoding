#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
// #define mod 1000000007 // equal to 10^9 + 7
// #define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        string arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = 0;
        ll matrix[n][m];
        memset(matrix,0,sizeof(matrix));
        for(int i=0;i<m;i++){
            if(arr[n -1][i] == '*'){
                matrix[n - 1][i] = 1;
            }
        }

        for(int i=n - 2;i>=0;i--){
            for(int j=m - 1;j>=0;j--){
                if(arr[i][j] == '*'){
                    matrix[i][j] = 1;
                    int val = 0;
                    if(i + 1 < n && j + 1 < m && j - 1 >= 0 && arr[i + 1][j] == '*' && arr[i + 1][j + 1] == '*' && arr[i + 1][j - 1] == '*'){
                        val = min(matrix[i + 1][j],min(matrix[i + 1][j + 1],matrix[i + 1][j - 1]));
                    }
                    matrix[i][j] += val;
                    continue;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                // cout<<matrix[i][j]<<" ";
                ans += matrix[i][j];
            }
            // cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}