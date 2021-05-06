#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }

        if(n == 2){
            cout<<-1<<endl;
            continue;
        }
        int k = 1;
        int matrix[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%2 == 0 ){
                    matrix[i][j] = k;
                    k++;
                }   
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%2 == 0){
                    cout<<matrix[i][j]<<" ";
                }
                else{
                    matrix[i][j] = k;
                    k++;
                    cout<<matrix[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

